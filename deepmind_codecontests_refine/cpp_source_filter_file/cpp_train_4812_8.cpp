#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
      cin >> val[i];
    }
    if (m == 1) {
      cout << max(val[0], val[n - 1]) << endl;
      continue;
    }
    if (k >= m - 1) {
      vector<int> vec;
      for (int i = 0; i <= m; i++) {
        vec.push_back(val[i]);
        vec.push_back(val[n - i - 1]);
      }
      cout << *max_element(vec.begin(), vec.end()) << endl;
      continue;
    }
    int res_glob = 0;
    for (int i = 0; i <= k; i++) {
      int ind_l = i;
      int ind_r = n - 1 - (k - i);
      int need = m - k - 1;
      int cur_res = 2000000000;
      for (int j = 0; j <= need; j++) {
        int cur_elem = ind_l + j;
        int cur_elem_left = ind_r - (need - j);
        cur_res = min(cur_res, max(val[cur_elem], val[cur_elem_left]));
      }
      res_glob = max(res_glob, cur_res);
    }
    cout << res_glob << endl;
  }
}
