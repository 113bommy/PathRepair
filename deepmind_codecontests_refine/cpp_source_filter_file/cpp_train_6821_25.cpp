#include <bits/stdc++.h>
using namespace std;
long long int i, j = 0, k, l, m1, m2, m3, m4, m, n, a1[100001], a2[1000001],
                 r[1000001] = {0}, c[1000001] = {0};
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    cin >> m1 >> m2 >> m3;
    if (m1 == 1) {
      a1[m2] = m3;
      r[m2] = i;
    } else {
      a2[m2] = m3;
      c[m2] = i;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a1[i] == 0 && a2[j] == 0)
        cout << "0";
      else {
        if (r[i] > c[j])
          cout << a1[i];
        else
          cout << a2[j];
      }
      if (j == m)
        cout << "\n";
      else
        cout << " ";
    }
  }
}
