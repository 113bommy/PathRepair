#include <bits/stdc++.h>
using namespace std;
void init() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c = {4, 8, 15, 16, 23, 42};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
  }
  vector<int> seq(6);
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      ++seq[0];
    } else {
      if (seq[a[i]] > 1) {
        ++seq[a[i]];
        --seq[a[i] - 1];
      }
    }
  }
  cout << n - 6 * seq[5] << endl;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  init();
  return 0;
}
