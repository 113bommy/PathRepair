#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.second != p2.second) return p1.second < p2.second;
  return p1.first < p2.first;
}
int main() {
  long long n, r, avg;
  cin >> n >> r >> avg;
  long long sum = 0;
  vector<pair<long long, long long> > data;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    data.push_back(make_pair(a, b));
    sum += (long long)a;
  }
  sort(data.begin(), data.end(), cmp);
  long long ans = 0;
  long long lim = avg * n, cur;
  if (sum >= lim) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    long long tmp = r - data[i].first;
    cur = data[i].second;
    sum += tmp;
    ans += (tmp * data[i].second);
    if (sum >= lim) break;
  }
  while (sum > lim) {
    sum--;
    ans -= cur;
  }
  cout << ans << "\n";
  return 0;
}
