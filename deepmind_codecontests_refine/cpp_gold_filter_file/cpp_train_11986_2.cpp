#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
struct LIS_T {
  int n, *a, dep[N], f[N], c[N], cnt, t;
  vector<int> V[N];
  inline void Clear() {
    for (int i = (0); i <= (n); ++i)
      dep[i] = 0, f[i] = -1, c[i] = 0, V[i].clear();
    cnt = 0;
  }
  inline void I(int x) {
    t = dep[x] = lower_bound(c + 1, c + cnt + 1, x) - c;
    c[t] = x, V[t].push_back(x), f[x] = c[t - 1], cnt += (t > cnt);
  }
  inline void Build() {
    for (int i = (1); i <= (n); ++i) I(a[i]);
  }
  inline void Init(int _a[], int _n) {
    a = _a, n = _n;
    Clear();
    Build();
  }
};
LIS_T T;
int n, m, a[N], _T, cnt;
vector<int> ans[N];
bool v[N];
inline void Del() {
  for (int x = T.c[T.cnt]; x; x = T.f[x]) v[x] = 0;
  m = n, n = 0, ans[++cnt].clear();
  for (int i = (1); i <= (m); ++i)
    if (v[a[i]])
      a[++n] = a[i];
    else
      ans[cnt].push_back(a[i]);
}
int main() {
  scanf("%d", &_T);
  while (_T--) {
    scanf("%d", &n), cnt = 0;
    for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]), v[i] = 1;
    while (n) {
      T.Init(a, n);
      if ((long long)T.cnt * (T.cnt + 1) / 2 > n)
        Del();
      else {
        for (int i = (1); i <= (T.cnt); ++i) ans[++cnt] = T.V[i];
        break;
      }
    }
    printf("%d\n", cnt);
    for (int i = (1); i <= (cnt); ++i) {
      printf("%d", ans[i].size());
      for (auto t : ans[i]) printf(" %d", t);
      printf("\n");
    }
  }
  return 0;
}
