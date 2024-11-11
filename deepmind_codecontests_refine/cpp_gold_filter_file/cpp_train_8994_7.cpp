#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    bool b = 1;
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
      if (v[i] == 1 || v[i] == n) b = 0;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m - 2; i++) {
      if ((v[i + 1] == v[i] + 1) && (v[i + 2] == v[i] + 2)) b = 0;
    }
    if (b)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
