#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.second != b.second)
    return a.second < b.second;
  else
    return a.first < b.first;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i].first = x - y, v[i].first = x + y;
  }
  sort(v.begin(), v.end(), cmp);
  int ans = 1;
  int last = 0;
  for (int i = 1; i < n; i++) {
    if (v[i].first >= v[last].second) {
      last = i;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
