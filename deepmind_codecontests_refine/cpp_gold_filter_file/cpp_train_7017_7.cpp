#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, a[1000021], c1, c2, c3, a1, a2, a3, cnt;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> c1 >> c2 >> c3;
    a1 = a[c1];
    a2 = a[c2];
    a3 = a[c3];
    cnt = a1 + a2 + a3;
    if (a1 == 0) {
      cnt++;
      cnt %= 3;
      if (cnt == 0) cnt = 3;
      a1 = cnt;
    }
    if (a2 == 0) {
      cnt++;
      cnt %= 3;
      if (cnt == 0) cnt = 3;
      a2 = cnt;
    }
    if (a3 == 0) {
      cnt++;
      cnt %= 3;
      if (cnt == 0) cnt = 3;
      a3 = cnt;
    }
    a[c1] = a1;
    a[c2] = a2;
    a[c3] = a3;
  }
  for (i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
}
