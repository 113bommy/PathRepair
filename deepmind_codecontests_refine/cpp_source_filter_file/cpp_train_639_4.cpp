#include <bits/stdc++.h>
using namespace std;
vector<long long> ve[100005];
long long vis[100005], z;
void solve() {
  vector<long long> v;
  vector<pair<long long, long long>> vp;
  map<long long, long long> mp;
  set<long long> st;
  multiset<long long> mst;
  long long n = 0, m = 0, i = 0, j = 0, k = 0, c = 0, l = 0, r = 0, p = 0,
            q = 0, x = 0, y = 0, z = 1, flag = 0, sum = 0;
  long long a[300005] = {0}, b[300005] = {0}, ans[300005];
  string s, t;
  cin >> n >> m >> k;
  for (i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  for (i = 0; i < m - 1; i++) {
    long long old = (a[i] - c) / k + (a[i] - c) % k != 0;
    long long new_ = ((a[i + 1] - c) / k) + ((a[i + 1] - c) % k != 0);
    if (old != new_) {
      c = i + 1;
      z++;
    }
  }
  cout << z << '\n';
}
bool imp = false;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  if (imp) cin >> t;
  long long j = t;
  while (t--) {
    solve();
  }
  return 0;
}
