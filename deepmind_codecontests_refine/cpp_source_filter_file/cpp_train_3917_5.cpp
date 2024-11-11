#include <bits/stdc++.h>
using namespace std;
template <int n>
using AI = array<int, n>;
const double eps = 1e-9;
const int oo = 0x3F3F3F3F;
const long long ooLL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1000000007;
template <typename T>
T sqr(T x) {
  return x * x;
}
const double PI = acos(-1.);
long long Round(double x) { return x < 0 ? x - .5 : x + .5; }
int main() {
  void run();
  run();
  return 0;
}
const int N = 1 << 18;
int n, u[N], sl, lo, nl;
vector<int> g[N];
void go(int v, int pr = -1) {
  u[v] = 1;
  for (auto &t : g[v]) {
    if (t == pr) continue;
    if (t == v) sl = 1;
    if (u[t])
      lo = 1;
    else
      go(t, v);
  }
  nl += 1;
}
void run() {
  scanf("%d", &n);
  for (int i = (0), _b(n); i < _b; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int rs = 1;
  for (int i = (0), _b(n); i < _b; ++i) {
    if (u[i]) continue;
    sl = 0;
    lo = 0;
    nl = 0;
    go(i);
    if (sl) continue;
    int t = 2;
    if (!lo) t = nl;
    rs = (rs * 1LL * t) % MOD;
  }
  printf("%d\n", rs);
}
