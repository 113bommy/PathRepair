#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <typename T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <typename T>
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
template <typename T>
inline void println(T first) {
  print(first), putchar('\n');
}
template <typename T>
inline void printsp(T first) {
  print(first), putchar(' ');
}
template <class T, class T1>
inline void print(T first, T1 second) {
  printsp(first), println(second);
}
template <class T, class T1, class T2>
inline void print(T first, T1 second, T2 z) {
  printsp(first), printsp(second), println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
pair<int, int> p[1010];
vector<pair<int, int> > ans;
void Move(int s, int t) {
  p[s].first -= p[t].first;
  p[t].first <<= 1;
  ans.push_back(pair<int, int>(p[t].second, p[s].second));
}
int main() {
  int n, m = 0;
  gn(n);
  for (int i = 1; i <= n; i++) {
    gn(p[i].first);
    p[i].second = i;
    m += (p[i].first > 0);
  }
  if (m <= 1) return puts("-1");
  for (int i = 1; i <= n - 2; i++) {
    sort(p + i, p + i + 3);
    while (p[i].first) {
      int q = p[i + 1].first / p[i].first;
      while (q) {
        if (q & 1)
          Move(i + 1, i);
        else
          Move(i + 2, i);
        q >>= 1;
      }
      sort(p + i, p + i + 3);
    }
  }
  println(ans.size());
  for (int i = 0; i < ans.size(); i++) print(ans[i].first, ans[i].second);
  return 0;
}
