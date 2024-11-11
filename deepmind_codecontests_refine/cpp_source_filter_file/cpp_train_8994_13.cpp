#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  int dis = 1, max_d = INT_MIN;
  if (a[0] == 1 || a[m - 1] == m) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i < m; i++) {
    if (a[i] - a[i - 1] == 1) {
      dis++;
      max_d = max(dis, max_d);
    } else {
      max_d = max(max_d, dis);
      dis = 1;
    }
  }
  if (max_d >= 3)
    cout << "NO";
  else {
    cout << "YES";
  }
  return 0;
}
