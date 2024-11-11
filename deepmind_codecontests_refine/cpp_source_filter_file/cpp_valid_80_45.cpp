#include <bits/stdc++.h>
using namespace std;
namespace start {
const int inf = INT_MAX >> 1;
const long long INF = INT64_MAX >> 1;
const double pi = acos(-1);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
long long read() {
  long long x;
  if (scanf("%lld", &x) != 1) exit(0);
  return x;
}
long long readfast() {
  long long x = 0, tag = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') tag = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return x * tag;
}
template <typename T>
void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
void print(long long x, bool e = 0) { printf("%lld%c", x, " \n"[e]); }
double readf() {
  double x;
  if (scanf("%lf", &x) != 1) exit(0);
  return x;
}
void printlf(double x, bool e = 0) { printf("%.12f%c", x, " \n"[e]); }
template <typename T>
vector<T> &operator<<(vector<T> &a, const T &b) {
  a.push_back(b);
  return a;
}
template <typename T>
T sqr(const T &x) {
  return x * x;
}
template <typename T>
void sortunique(vector<T> &a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
const int N = 600010;
const double eps = 1e-9;
const int mod = (1 ? 1000000007 : 998244353);
int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
int qpow(int a, long long b, int m = mod) {
  int ans = 1;
  for (; b; a = mul(a, a, m), b >>= 1)
    if (b & 1) ans = mul(ans, a, m);
  return ans;
}
}  // namespace start
using namespace start;
char s[N];
int a[N];
void Solve() {
  int n = read();
  scanf("%s", s + 1);
  int sum = 0;
  for (int i = (1), ib = (n + 1); i < ib; i++) a[i] = s[i] - '0', sum += a[i];
  if (sum == n) {
    printf("%d %d %d %d\n", 1, n - 1, 2, n);
    return;
  }
  for (int i = (1), ib = (n + 1); i < ib; i++)
    if (a[i] == 0) {
      if (i <= n / 2) {
        printf("%d %d %d %d\n", i, n, i + 1, n);
        return;
      } else {
        printf("%d %d %d %d\n", 1, i - 1, 1, i);
        return;
      }
    }
}
signed main() {
  int T = 1;
  T = read();
  for (int ca = (1), ib = (T + 1); ca < ib; ca++) {
    Solve();
  }
  return 0;
}
