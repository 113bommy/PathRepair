#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> a[n + m - 1], b[n + m - 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i + j].push_back(x);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      b[i + j].push_back(x);
    }
  }
  for (int i = 0; i < n + m - 1; i++) {
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
