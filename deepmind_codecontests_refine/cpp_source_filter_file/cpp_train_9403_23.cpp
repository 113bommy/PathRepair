#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, j, a, i, y, m;
  vector<int> v;
  cin >> n;
  cin >> k;
  j = k;
  for (i = 0; i < n; i++) {
    cin >> y;
    v.push_back(y);
  }
  for (a = 0; a <= n - k - 1; a++) {
    if (v[k + a] == v[k - 1] && v[k + a] > 0)
      j++;
    else
      break;
  }
  if (v[k - 1] == 0) {
    for (m = 0; m < k - 1; m++) {
      if (v[k - m - 1] == 0) j--;
    }
  }
  cout << j;
  return 0;
}
