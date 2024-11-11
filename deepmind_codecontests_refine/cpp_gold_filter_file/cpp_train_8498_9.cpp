#include <bits/stdc++.h>
using namespace std;
struct fast_reader {
  fast_reader &operator,(int &x) {
    scanf("%d", &x);
    return *this;
  }
  fast_reader &operator,(signed long long &x) {
    scanf(
        "%"
        "ll"
        "d",
        &x);
    return *this;
  }
  fast_reader &operator,(double &x) {
    scanf("%lf", &x);
    return *this;
  }
  fast_reader &operator,(long double &x) {
    scanf("%Lf", &x);
    return *this;
  }
  fast_reader &operator,(char &x) {
    do x = getchar();
    while (x == ' ' || x == '\n');
    return *this;
  }
  fast_reader &operator,(char *x) {
    scanf("%s", x);
    return *this;
  }
  fast_reader &operator,(string &x) {
    int c;
    do c = getchar();
    while (c == ' ' || c == '\n');
    x.clear();
    do x.push_back(c), c = getchar();
    while (c != ' ' && c != '\n' && c != EOF);
    ungetc(c, stdin);
    return *this;
  }
  fast_reader &line(string &x) {
    int c = getchar();
    x.clear();
    while (c != '\n' && c != EOF) x.push_back(c), c = getchar();
    return *this;
  }
} in;
struct fast_writer {
  fast_writer &operator,(const int x) {
    printf("%d", x);
    return *this;
  }
  fast_writer &operator,(const signed long long x) {
    printf(
        "%"
        "ll"
        "d",
        x);
    return *this;
  }
  fast_writer &operator,(const double x) {
    printf(
        "%."
        "12"
        "lf",
        x);
    return *this;
  }
  fast_writer &operator,(const long double x) {
    printf(
        "%."
        "12"
        "Lf",
        x);
    return *this;
  }
  fast_writer &operator,(const char x) {
    putchar(x);
    return *this;
  }
  fast_writer &operator,(const char *x) {
    printf("%s", x);
    return *this;
  }
  fast_writer &operator,(const string &x) { return operator,(x.c_str()); }
  fast_writer &operator-() {
    fflush(stdout);
    return *this;
  }
} out;
inline void quit() { exit(EXIT_SUCCESS); }
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T gcd(T a, T b) {
  T c;
  while (a) c = a, a = b % a, b = c;
  return b;
}
template <class T>
inline T lcm(T a, T b) {
  return (a / gcd(a, b)) * b;
}
template <class T>
inline T pow(T a, T n, T m) {
  T b = 1;
  while (n) {
    if (n & 1) b = (b * a) % m;
    a = (a * a) % m, n >>= 1;
  }
  return b;
}
static const signed long long MOD = (signed long long)1e9 + 7;
static const long double EPS = (long double)1e-12;
const int N = int(1e4) + 1;
int n, l, r;
int a[N];
vector<int> bad, good;
bool f[2][N];
int g[2][N];
int main() {
  in, n, l, r;
  for (int i = 0; i < n; i++) in, a[i];
  for (int i = 0; i < n; i++) {
    int x;
    in, x;
    if (x == 0)
      bad.push_back(a[i]);
    else
      good.push_back(a[i]);
  }
  f[0][0] = true;
  for (int i = 0; i < bad.size(); i++) {
    int x = i & 1;
    int y = 1 - x;
    for (int j = 0; j < bad[i]; j++) f[y][j] = f[x][j];
    for (int j = bad[i]; j < N; j++) f[y][j] = f[x][j] || f[x][j - bad[i]];
  }
  sort(good.begin(), good.end(), greater<int>());
  for (int i = 0; i < N; i++) g[0][i] = good.size() + 1;
  g[0][0] = 0;
  for (int i = 0; i < good.size(); i++) {
    int x = i & 1;
    int y = 1 - x;
    for (int j = 0; j < good[i]; j++) g[y][j] = g[x][j];
    for (int j = good[i]; j < N; j++) {
      g[y][j] = g[x][j];
      if (g[x][j - good[i]] < good.size()) g[y][j] = min(g[y][j], i + 1);
    }
  }
  int f_ = bad.size() & 1;
  int g_ = good.size() & 1;
  int s_ = 0;
  for (int i = 0; i < good.size(); i++) s_ += good[i];
  int ans = 0;
  for (int i = 0; i < r; i++) {
    if (!f[f_][i]) continue;
    int s = s_, k = good.size();
    for (int j = std::max(l - i, 0); j <= std::max(r - i, 0); j++) {
      while (k > 0 && i + j + s - good[good.size() - k] > r)
        s -= good[good.size() - k], k--;
      int k_ = good.size() - g[g_][j];
      if (g[g_][j] <= good.size() && j < s_ - s) k_++;
      ans = max(ans, min(k, k_));
    }
  }
  out, ans;
  quit();
}
