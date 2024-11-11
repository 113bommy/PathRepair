#include <bits/stdc++.h>
inline void read(int &x) { scanf("%d", &x); }
inline void read(long long &x) { scanf("%I64d", &x); }
inline void read(double &x) { scanf("%lf", &x); }
inline void read(long double &x) {
  double tmp;
  read(tmp);
  x = tmp;
}
template <class T>
inline void read(T *a, int n) {
  for (long long i = (0); i < (n); ++i) read(a[i]);
}
inline void write(int x) { printf("%d", x); }
inline void write(long long x) { printf("%I64d", x); }
inline void write(double x) { printf("%.10lf", x); }
inline void write(long double x) { printf("%.10lf", (double)x); }
template <class T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
template <class T>
inline void writeln(T *a, int n) {
  for (long long i = (0); i < (n); ++i) write(a[i]);
  putchar('\n');
}
template <class T>
inline void writelnln(T *a, int n) {
  for (long long i = (0); i < (n); ++i) writeln(a[i]);
}
int n, m;
int a[1086];
double dp[1086][1086];
int main() {
  read(n);
  read(m);
  read(a + 1, n);
  for (long long i = (1); i <= (n); ++i)
    for (long long j = (1); j <= (n); ++j) dp[i][j] = (a[i] > a[j]);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (long long i = (1); i <= (n); ++i)
      if (i != a && i != b) {
        dp[i][a] = dp[i][b] = (dp[i][a] + dp[i][b]) / 2;
        dp[a][i] = dp[b][i] = (dp[a][i] + dp[b][i]) / 2;
      }
    dp[a][b] = dp[b][a] = 0.5;
  }
  double ans = 0;
  for (long long i = (1); i <= (n); ++i)
    for (long long j = (i + 1); j <= (n); ++j) ans += dp[i][j];
  printf("%.10lf\n", ans);
  return 0;
}
