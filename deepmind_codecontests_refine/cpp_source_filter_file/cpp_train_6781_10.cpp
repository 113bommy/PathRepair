#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> fac[N], mul[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) fac[j].push_back(i);
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y, c = 0;
    cin >> x >> y;
    if (y == 0) {
      cout << fac[x].size() + 1 << "\n";
      for (int j : fac[x]) mul[j].push_back(i);
      continue;
    }
    for (int j : fac[x]) {
      int a = lower_bound(mul[j].begin(), mul[j].end(), i - j) - mul[j].begin();
      int b = lower_bound(mul[j].begin(), mul[j].end(), i - 1) - mul[j].begin();
      int aa =
          upper_bound(mul[j].begin(), mul[j].end(), i - j) - mul[j].begin();
      int bb =
          upper_bound(mul[j].begin(), mul[j].end(), i - 1) - mul[j].begin();
      int z;
      if (b == bb) {
        if (a == aa)
          z = b - a;
        else
          z = b - a;
      } else {
        if (a == aa)
          z = b - a + 1;
        else
          z = b - a + 1;
      }
      if (z == 0) {
        c++;
      }
    }
    cout << c << "\n";
    for (int j : fac[x]) mul[j].push_back(i);
  }
  return 0;
}
