#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first) return x.second < y.second;
  return x.first < y.first;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n], b[n];
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    cin >> b[i];
  }
  int c[k];
  for (i = 0; i < k; i++) cin >> c[i];
  pair<int, int> p[n];
  for (i = 0; i < n; i++) {
    p[i] = make_pair(b[i], a[i]);
  }
  sort(p, p + n, comp);
  map<int, int> m1, m2;
  for (i = 0; i < n; i++) {
    m1[p[i].first] = p[i].second;
  }
  for (auto itr = m1.begin(); itr != m1.end(); itr++) {
    m2[itr->second] = itr->first;
  }
  int cnt = 0;
  for (i = 0; i < k; i++) {
    if (m2[c[i]] == 0) cnt++;
  }
  cout << cnt << endl;
}
