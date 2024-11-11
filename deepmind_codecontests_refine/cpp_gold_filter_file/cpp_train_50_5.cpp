#include <bits/stdc++.h>
using namespace std;
bool u[101];
int main() {
  int n, m, k, t;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> t;
      u[t] = 1;
    }
  }
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    if (!u[i]) f = 0;
  }
  if (f)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
