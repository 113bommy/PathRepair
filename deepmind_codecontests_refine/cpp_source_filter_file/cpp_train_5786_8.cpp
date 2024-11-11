#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
template <class T1, class T2, class T3>
inline void gn(T1 &x1, T2 &x2, T3 &x3) {
  gn(x1, x2), gn(x3);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = (long long)a * a % m)
    if (b & 1) ans = (long long)ans * a % m;
  return ans;
}
pair<pair<int, int>, int> p[16];
int dp[65536][121], N[2];
int main() {
  int n, sum = 0;
  gn(n);
  for (int i = 0; i < n; i++) {
    char c;
    scanf(" %c %d %d", &c, &p[i].first.first, &p[i].first.second);
    p[i].second = c == 'R';
    sum += p[i].first.first;
  }
  int mx = min(65536, 1 << n), sz = n * (n - 1) / 2 + 1;
  for (int i = 0; i < mx; i++) {
    for (int j = 0; j < sz; j++) {
      dp[i][j] = 0x3f3f3f3f;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < mx; i++) {
    N[0] = N[1] = 0;
    for (int j = 0; j < n; j++)
      if ((((i) >> (j)) & 1)) {
        N[p[j].second]++;
      }
    for (int j = 0; j < n; j++)
      if (!(((i) >> (j)) & 1)) {
        int u = i | (1 << j), num = min(p[j].first.first, N[1]),
            cnt = max(p[j].first.second - N[0], 0);
        for (int k = 0; k < sz; k++)
          if (k + num < sz) {
            smin(dp[u][k + num], dp[i][k] + cnt);
          }
      }
  }
  int ans = 0x3f3f3f3f;
  for (int i = 1; i < sz; i++) {
    smin(ans, max(sum - i, dp[mx - 1][i]));
  }
  println(ans + n);
}
