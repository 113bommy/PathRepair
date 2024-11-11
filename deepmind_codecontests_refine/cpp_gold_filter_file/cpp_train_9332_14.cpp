#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int64_t> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int64_t> all_results(n);
  for (int i = 0; i < n; ++i) {
    int64_t cur_res = INT64_MIN;
    for (int ai = 0; ai < n; ++ai) {
      if (ai == i) {
        continue;
      }
      for (int bi = 0; bi < m; ++bi) {
        cur_res = max(cur_res, a[ai] * b[bi]);
      }
    }
    all_results[i] = cur_res;
  }
  sort(all_results.begin(), all_results.end());
  cout << all_results[0] << "\n";
  return 0;
}
