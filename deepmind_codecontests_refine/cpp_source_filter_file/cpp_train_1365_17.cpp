#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int n, d;
  cin >> n >> d;
  vector<int> pont(n);
  vector<int> next(n);
  for (int i = 0; i < n; i++) {
    cin >> pont[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> next[i];
  }
  int res = d;
  int p = pont[d] + next[0];
  int j = d - 1;
  for (int i = 1; i < n && j >= 0; i++) {
    if (pont[j] + next[i] <= p) {
      res--;
      j--;
    }
  }
  cout << res << endl;
}
