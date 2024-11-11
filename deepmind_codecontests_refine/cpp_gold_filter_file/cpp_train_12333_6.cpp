#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long>& p1, pair<long long, long long>& p2) {
  return p1.second < p2.second;
}
signed main() {
  long long n, r, avg, sum = 0, ans = 0, temp, index = 0;
  cin >> n >> r >> avg;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    sum += v[i].first;
  }
  sort(v.begin(), v.end(), cmp);
  while (sum < avg * n) {
    temp = min(avg * n - sum, r - v[index].first);
    ans += temp * v[index].second;
    sum += temp;
    index++;
  }
  cout << ans;
  return 0;
}
