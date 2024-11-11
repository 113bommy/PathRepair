#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
const int inf = 1e9;
const int N = 2e5 + 10;
bool flag;
struct ftree {
  vector<int> a;
  ftree(int n) { a.resize(n + 1); }
  long long qu(int n) {
    long long res = 0;
    for (int i = n; i >= 0; i = (i + 1 & i) - 1) res += a[i];
    return res;
  }
  long long qu(int l, int r) { return qu(r) - qu(l - 1); }
  void set(int x) {
    for (; x < (int)a.size(); x |= x + 1) a[x]++;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), rv;
  cin >> a;
  rv = a;
  map<int, int> mp;
  ftree ftr(n);
  sort(rv.begin(), rv.end());
  rv.erase(unique(rv.begin(), rv.end()), rv.end());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(rv.begin(), rv.end(), a[i]) - rv.begin();
  long long ans = 0;
  for (auto now : a) {
    int l = ftr.qu(0, now - 1), r = ftr.qu(now + 1, (int)rv.size());
    ans += min(l, r);
    ftr.set(now);
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    flag = 0;
    solve();
    cout << '\n';
  }
  return 0;
}
