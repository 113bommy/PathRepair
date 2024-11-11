#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  if (n > m) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= m;
  }
  vector<int> p(m, -1), np(m, -1);
  for (int i = 0; i < n && p[0] == -1; i++) {
    int v = a[i];
    copy(p.begin(), p.end(), np.begin());
    if (np[v] == -1) np[v] = 1;
    for (int j = 0; j < m; j++) {
      if (p[j] != -1 && p[(j + v) % m] == -1) {
        np[(j + v) % m] = 1;
      }
    }
    copy(np.begin(), np.end(), p.begin());
  }
  if (p[0] == -1)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
