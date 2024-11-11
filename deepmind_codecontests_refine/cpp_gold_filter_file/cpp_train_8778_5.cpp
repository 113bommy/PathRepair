#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a;
  for (int i = 0; i < m; i++) {
    int q, w;
    cin >> q >> w;
    a.push_back(make_pair(q, w));
  }
  sort(a.begin(), a.end(), comp);
  int i = 0;
  int ma = 0;
  while (n > 0 && i <= m - 1) {
    if (n >= a[i].first) {
      n -= a[i].first;
      ma += a[i].first * a[i].second;
    } else {
      ma += n * a[i].second;
      n = 0;
    }
    i++;
  }
  cout << ma << endl;
  return 0;
}
