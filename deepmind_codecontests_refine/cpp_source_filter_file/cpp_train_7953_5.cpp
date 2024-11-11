#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 100;
const int MOD = 1000 * 1000 * 1000 + 9;
const int SIZE = 5000;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > p(100500);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
    p[a[i]].push_back(i);
  }
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j)
      if (a[j] < a[i]) ++cur;
  }
  for (int k = 1; k < 100500; ++k) {
    if (p[k].size() == 0) continue;
    int best = 0;
    int before = 0;
    int after = 0;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > -k && a[i] < k) ++after;
    }
    int i = 0;
    for (int cnt = 0; cnt < p[k].size(); ++cnt) {
      for (; i != p[k][cnt]; ++i) {
        if (a[i] > -k && a[i] <= k) ++before, --after;
      }
      tmp += before - after;
      if (tmp < best) best = tmp;
    }
    cur += best;
  }
  cout << cur << endl;
  return 0;
}
