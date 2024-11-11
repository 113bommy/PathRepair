#include <bits/stdc++.h>
using namespace std;
long long int MAX = 4e5 + 1;
long long int mod = 998244353LL;
vector<long long int> v;
vector<vector<long long int> > p;
long long int n, m;
bool check(long long int cnt) {
  vector<long long int> temp = v;
  vector<vector<long long int> > day(cnt + 1);
  vector<long long int> t(n, -1);
  long long int tot = 0;
  for (long long int i = 0; i < n; i++) tot += 2 * v[i];
  for (auto &x : p) {
    if (x[0] > cnt) continue;
    day[x[0]].push_back(x[1]);
    t[x[1]] = max(t[x[1]], x[0]);
  }
  long long int c = 0;
  for (long long int i = 0; i < cnt + 1; i++) {
    for (auto &x : day[i]) {
      if (t[x] > i) continue;
      long long int m = min(c, v[x]);
      c -= m;
      temp[x] -= m;
      tot -= 2 * m;
    }
    if (tot == 0 || c >= tot) return true;
    c++;
  }
  return false;
}
void solve() {
  cin >> n >> m;
  long long int tot = 0;
  v.resize(n);
  p.assign(m, vector<long long int>(2));
  for (long long int i = 0; i < n; i++) cin >> v[i];
  for (long long int i = 0; i < m; i++) {
    cin >> p[i][0] >> p[i][1];
    p[i][1]--;
  }
  long long int lo = 0, hi = MAX - 1;
  while (lo < hi) {
    long long int mid = lo + (hi - lo) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  for (long long int i = 0; i < t; i++) {
    solve();
  }
}
