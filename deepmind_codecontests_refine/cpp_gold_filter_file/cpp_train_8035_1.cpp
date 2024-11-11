#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF64 = ll(4e18) + 5;
const db EPS = 1e-9;
const db PI = acos((db)-1);
void solve() {
  int n;
  cin >> n;
  vi a(n);
  int livre = 1;
  map<int, int> m;
  vi b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    if (m[b[i]] == 0) {
      m[b[i]] = livre++;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] = m[a[i]];
  }
  int last = livre - 1;
  int ini = 1;
  vi pri(n + 2, INF);
  vi ult(n + 2, -1);
  for (int i = 0; i < n; i++) {
    pri[a[i]] = min(pri[a[i]], i);
    ult[a[i]] = max(ult[a[i]], i);
  }
  int fim = 1;
  vi ans(n + 2);
  for (int i = ini; i <= last; i++) {
    ans[i] = 1;
    if (i == ini) continue;
    if (pri[i] > ult[i - 1]) {
      ans[i] += ans[i - 1];
    }
    fim = max(fim, ans[i]);
  }
  int answer = last - fim;
  cout << answer << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
