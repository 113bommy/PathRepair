#include <bits/stdc++.h>
#pragma GCC optimization("O3")
using namespace std;
template <typename T>
inline void Cin(T& first) {
  char c;
  T sign = 1;
  first = 0;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) first = first * 10 + c - '0';
  first *= sign;
}
template <typename T>
inline void Out(T first) {
  if (first > 9) Out(first / 10);
  putchar(first % 10 + '0');
}
template <typename T>
inline void Cout(T first, char c) {
  if (first < 0) putchar('-');
  first = abs(first);
  Out(first);
  putchar(c);
}
template <typename T, typename... Args>
inline void Cin(T& a, Args&... args) {
  Cin(a);
  Cin(args...);
}
template <typename T, typename... Args>
inline void Cout(T a, char c, Args... args) {
  Cout(a, c);
  Cout(args...);
}
const int N = 107;
const long double eps = 1e-8;
const long double e = 2.7182818284590452353602874713527;
int n, k, first[N], second[N];
long double low, high, mid, s, w, p[N], f[N][N];
void Enter() {
  cin >> n >> k >> w;
  w = 1 - w / 1000;
  for (int i = 0; i <= n; ++i) cin >> first[i] >> second[i];
}
int SqrDis(int i) {
  return (first[i] - first[0]) * (first[i] - first[0]) +
         (second[i] - second[0]) * (second[i] - second[0]);
}
bool Check() {
  for (int i = 1; i <= n; ++i) {
    if ((long double)SqrDis(i) <= mid * mid)
      p[i] = 1;
    else
      p[i] = pow(e, (1 - (long double)SqrDis(i) / (mid * mid)));
  }
  memset(&f, 0, sizeof f);
  f[1][1] = p[1];
  f[1][0] = 1 - p[1];
  for (int i = 2; i <= n; ++i) {
    f[i][0] = f[i - 1][0] * (1 - p[i]);
    f[i][i] = f[i - 1][i - 1] * p[i];
    for (int j = 1; j < i; ++j)
      f[i][j] = f[i - 1][j - 1] * p[i] + f[i - 1][j] * (1 - p[i]);
  }
  s = 0;
  for (int i = k; i <= n; ++i) s += f[n][i];
  return s >= w;
}
void Solve() {
  low = eps, high = 2000;
  while (low + eps <= high) {
    mid = (low + high) / 2.0;
    if (Check())
      high = mid - eps;
    else
      low = mid + eps;
  }
  cout << fixed << setprecision(9) << low;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("test"
            ".inp",
            "r")) {
    freopen(
        "test"
        ".inp",
        "r", stdin);
    freopen(
        "test"
        ".out",
        "w", stdout);
  }
  Enter(), Solve();
  return 0;
}
