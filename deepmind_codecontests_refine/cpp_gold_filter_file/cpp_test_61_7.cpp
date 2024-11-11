#include <bits/stdc++.h>
const int INF = 1e8;
const long long MOD = 1e9 + 7;
using namespace std;
bool cases = 1;
long long x[200005];
long long y[200005];
void solve(int nc) {
  long long n, a, b;
  cin >> n;
  vector<pair<int, int> > v;
  long long xd = 0, yd = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(pair<int, int>(a, b));
    if (x[a] == 0) xd++;
    if (y[b] == 0) yd++;
    x[a]++;
    y[b]++;
  }
  long long ans = n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    a = v[i].first, b = v[i].second;
    ans -= (x[a] - 1) * (y[b] - 1);
  }
  for (int i = 0; i < n; i++) {
    a = v[i].first, b = v[i].second;
    x[a] = y[b] = 0;
  }
  cout << ans;
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  if (cases) cin >> t;
  for (int nc = 1; nc < t + 1; nc++) solve(nc);
  return 0;
}
