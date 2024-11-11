#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int b[n], g[m];
  for (int i = 0; i < n; i++) b[i] = 0;
  for (int i = 0; i < m; i++) g[i] = 0;
  int hb, hg;
  cin >> hb;
  for (int i = 0; i < hb; i++) {
    int t;
    cin >> t;
    b[t] = 1;
  }
  cin >> hg;
  for (int i = 0; i < hg; i++) {
    int t;
    cin >> t;
    g[t] = 1;
  }
  int ma = max(m, n);
  int i = 0, j = 0;
  int k = 0;
  while (k <= 2 * m * n) {
    i = i % n;
    j = j % m;
    if (b[i] || g[j]) {
      b[i] = 1;
      g[j] = 1;
    }
    i++;
    j++;
    k++;
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 1) {
      k++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (g[i] == 1) {
      k++;
    }
  }
  if (k == (m + n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
