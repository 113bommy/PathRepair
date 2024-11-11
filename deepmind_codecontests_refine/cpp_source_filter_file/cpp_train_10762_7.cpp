#include <bits/stdc++.h>
using namespace std;
const int MX_TM = 1e+6 + 5;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int t, c;
    cin >> t >> c;
    a.push_back({t, c});
  }
  sort(a.begin(), a.end());
  int mx_ans = 0, f_tm = 0;
  int c_sz = 0;
  int pos = 0;
  int i;
  for (i = 0; i < MX_TM; i++) {
    c_sz = max(c_sz - 1, 0);
    if (a[pos].first == i) {
      c_sz += a[0].second;
      pos++;
    }
    mx_ans = max(mx_ans, c_sz);
    if (pos == n) {
      break;
    }
  }
  cout << i + c_sz << " " << mx_ans;
}
