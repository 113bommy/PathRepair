#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > p;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first)
    return 1;
  else if (a.first < b.first)
    return 0;
  if (a.second <= b.second)
    return 1;
  else
    return 0;
}
int main() {
  int n, k, i, pi, ti, cnt = 1;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> pi >> ti;
    p.push_back(make_pair(pi, ti));
  }
  sort(p.begin(), p.end(), cmp);
  for (i = k; i < p.size(); i++) {
    if (p[k - 1].first == p[i].first && p[k - 1].second == p[i].second) cnt++;
  }
  for (i = k - 2; i >= 0; i--) {
    if (p[k - 1].first == p[i].first && p[k - 1].second == p[i].second) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
