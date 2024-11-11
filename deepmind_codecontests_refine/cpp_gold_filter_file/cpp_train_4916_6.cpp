#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
bool p[5009];
vector<int> pr;
void pre() {
  for (int i = 2; i <= (5000); ++i) {
    if (!p[i]) {
      pr.push_back(i);
      for (int j = i; j <= 5000; j += i) p[j] = 1;
    }
  }
  reverse(pr.begin(), pr.end());
}
vector<int> v;
vector<int> u;
int n;
int c(int k, int p) {
  int cur = p;
  int cnt = 0;
  while (cur <= k) cnt += k / cur, cur *= p;
  return cnt;
}
long long solve(int l, int r, int tot, int ix, long long ans) {
  if (ix == (int)(pr).size()) return ans;
  int i = l;
  long long fns = ans;
  long long gg = 0;
  int cnt2 = tot;
  while (i < r) {
    int curcnt = 0;
    int j = i;
    int cnt = c(v[i], pr[ix]);
    while (j < r && (c(v[j], pr[ix]) == cnt)) curcnt += u[j], j++;
    long long cur = ans + 1ll * (n - 2 * cnt2) * cnt - gg;
    fns = min(fns, cur);
    fns = min(fns, solve(i, j, curcnt, ix + 1, cur));
    cnt2 -= curcnt;
    gg += 2ll * curcnt * cnt;
    i = j;
  }
  return fns;
}
int cntx[5009];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  pre();
  cin >> n;
  long long cost = 0;
  v.resize(n);
  u.resize(n);
  map<int, int> m;
  for (int i = 0; i < (n); ++i) {
    int x;
    cin >> x;
    cntx[x]++;
  }
  for (int i = 0; i <= (5000); ++i) {
    if (cntx[i] == 0) continue;
    v.push_back(i);
    u.push_back(cntx[i]);
    for (int j = 0; j < ((int)(pr).size()); ++j)
      cost += 1ll * cntx[i] * c(i, pr[j]);
  }
  cout << solve(0, (int)(v).size(), n, 0, cost);
  return 0;
}
