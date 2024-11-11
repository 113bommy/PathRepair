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
template <class T1, class T2, class T3, class T4>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  gn(x1, x2, x3), gn(x4);
}
template <class T1, class T2, class T3, class T4, class T5>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  gn(x1, x2, x3, x4), gn(x5);
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
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
template <class T1, class T2, class T3, class T4, class T5>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {
  printsp(x1), printsp(x2), printsp(x3), printsp(x4), println(x5);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
int dp[55][55][55][110];
int func[110];
int rev[110];
int C(int n, int k) {
  int ans = (long long)func[n] * rev[n - k] % 1000000007 * rev[k] % 1000000007;
  return ans;
}
int pre() {
  func[0] = 1;
  rev[0] = 1;
  for (int i = 1; i < 110; i++)
    func[i] = (long long)func[i - 1] * i % 1000000007;
  for (int i = 1; i < 110; i++)
    rev[i] = power(func[i], 1000000007 - 2, 1000000007);
  return 0;
}
int main() {
  pre();
  int N, M, K;
  gn(N, M, K);
  for (int i = 1; i <= N / 2; i++) dp[2][i][i][1] = 1;
  int ans = 0;
  for (int i = 2; i <= M and i <= N / 2 + 1; i++)
    for (int j = 1; j <= N / 2; j++)
      for (int k = 1; k <= N / 2; k++)
        for (int w = 1; w <= K; w++) {
          int val = dp[i][j][k][w];
          if (val == 0) continue;
          ans = (ans + (long long)(M - i + 1) * val % 1000000007) % 1000000007;
          for (int r = 1; r + j <= N / 2; r++) {
            long long ww = (long long)w * C(k + r - 1, r);
            if (ww > k) break;
            dp[i + 1][j + r][r][ww] =
                (dp[i + 1][j + r][r][ww] + val) % 1000000007;
          }
        }
  cout << ans << endl;
}
