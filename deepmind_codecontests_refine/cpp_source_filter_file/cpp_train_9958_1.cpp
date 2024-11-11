#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c, ck = 1, ans = 0, a, b;
  cin >> n >> m;
  vector<int> v1, v2;
  for (int i = 0; i < n; i++) cin >> c, v1.push_back(c);
  for (int i = 0; i < m; i++) cin >> c, v2.push_back(c);
  a = v1[0];
  b = v2[0];
  int i = 1, j = 1;
  while (ck) {
    if (a == b) {
      ans++;
      if (i + 1 >= n && j + 1 >= m)
        ck = 0;
      else {
        a = v1[i];
        b = v2[j];
        i++;
        j++;
      }
    }
    if (a < b) {
      a += v1[i];
      i++;
    } else if (a > b) {
      b += v2[j];
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}
