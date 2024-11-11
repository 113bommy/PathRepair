#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  int a[n + 3], b[m + 3];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int i = 0, j = 0;
  long s1 = a[0], s2 = b[0];
  while (i < n && j < m) {
    if (s1 == s2) {
      cnt++;
      i++;
      j++;
      s1 = a[i];
      s2 = b[j];
    } else if (s1 > s2) {
      j++;
      s2 += b[j];
    } else if (s1 < s2) {
      i++;
      s1 += a[i];
    }
  }
  cout << cnt;
  return 0;
}
