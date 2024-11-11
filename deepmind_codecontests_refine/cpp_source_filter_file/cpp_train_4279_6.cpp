#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  vector<bool> occ(n);
  for (int i = 0; i < n; i++) {
    if (s.substr(i, m) == t) {
      occ[i] = 1;
    }
  }
  vector<int> prefixOcc(n + 1);
  prefixOcc[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefixOcc[i] = prefixOcc[i - 1] + occ[i - 1];
  }
  while (q--) {
    int left, right;
    cin >> left >> right;
    left--;
    right--;
    if (right - left + 1 < m or right - m < 0) {
      cout << '0' << endl;
      ;
      continue;
    }
    int prefLeft = prefixOcc[left];
    int prefRight = prefixOcc[right - m + 2];
    cout << prefRight - prefLeft << endl;
  }
}
