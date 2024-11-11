#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> a(m);
  vector<int> b(n);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int exists;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      cin >> exists;
      if (exists == 0) {
        cout << 0 << " ";
      } else {
        cout << min(a[j], b[i]) << " ";
      }
    }
    cin >> exists;
    if (exists == 0) {
      cout << 0 << " ";
    } else {
      cout << min(a[m - 1], b[i]) << " ";
    }
  }
  return 0;
}
