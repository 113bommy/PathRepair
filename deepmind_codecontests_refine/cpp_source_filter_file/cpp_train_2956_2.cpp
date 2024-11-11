#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n + 1];
  a[0] = 0;
  for (int i = 0; i < n; i++) {
    int t, c;
    cin >> c >> t;
    a[i + 1] = a[i] + t * c;
  };
  vector<int> res;
  int r = n - 1;
  int l = 0;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    r = n;
    while (r - l > 1) {
      if (a[(r + l) / 2] <= x)
        l = (r + l) / 2;
      else
        r = (r + l) / 2;
    };
    res.push_back(l + 1);
  };
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}
