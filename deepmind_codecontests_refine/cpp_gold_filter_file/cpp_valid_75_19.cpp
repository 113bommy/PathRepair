#include <bits/stdc++.h>
using namespace std;
unsigned long calc(vector<unsigned long> &cave) {
  unsigned long n = cave[0], min = cave[1] + 1, cur = min + 1;
  for (unsigned long i = 2; i < n + 1; i++) {
    if (cur <= cave[i]) {
      min += (cave[i] - cur + 1);
      cur = cave[i] + 2;
    } else
      ++cur;
  }
  return min;
}
void proc(vector<vector<unsigned long>> &caves,
          vector<pair<unsigned long, unsigned long>> &mins, int n) {
  unsigned long mi = mins[0].first, cur = mi + caves[mins[0].second][0];
  for (int i = 1; i < n; i++) {
    if (cur < mins[i].first) {
      mi += mins[i].first - cur;
      cur = mins[i].first + caves[mins[i].second][0];
    } else
      cur += caves[mins[i].second][0];
  }
  cout << mi << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned long n;
    cin >> n;
    vector<vector<unsigned long>> a(n);
    vector<pair<unsigned long, unsigned long>> mins(n);
    for (unsigned long i = 0; i < n; i++) {
      unsigned long k;
      cin >> k;
      a[i].resize(k + 1, 0);
      a[i][0] = k;
      for (unsigned long j = 0; j < k; j++) cin >> a[i][1 + j];
      mins[i] = pair<unsigned long, unsigned long>(calc(a[i]), i);
    }
    sort(
        mins.begin(), mins.end(),
        [](pair<unsigned long, unsigned long> a,
           pair<unsigned long, unsigned long> b) { return a.first < b.first; });
    proc(a, mins, n);
  }
}
