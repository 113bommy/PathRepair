#include <bits/stdc++.h>
using namespace std;
bool myfun(const pair<int, int>& i, const pair<int, int>& j) {
  if (i.first < j.first) return false;
  if (j.first < i.first) return true;
  return j.second < i.second;
}
int main() {
  int n, k, a, b;
  vector<pair<int, int> > v;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end(), myfun);
  a = v[k - 1].first;
  b = v[k - 1].second;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].first == a && v[i].second == b) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
