#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    mp[make_pair(x, y)] = 1;
  }
  if (n == 1) {
    cout << -1;
    return 0;
  }
  int m1 = -1, m2 = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (mp[make_pair(i, j)] == 0) {
        m1 = i;
        m2 = j;
        break;
      }
    }
    if (m1 != -1) {
      break;
    }
  }
  if (m1 == -1 && m2 == -1) {
    cout << "NO";
    return 0;
  }
  cout << "YES"
       << "\n";
  for (int i = 1, j = 3; i <= n; i++) {
    if (i == m1) {
      cout << 1 << " ";
      continue;
    }
    if (i == m2) {
      cout << 2 << " ";
      continue;
    }
    cout << j << " ";
    j++;
  }
  cout << "\n";
  for (int i = 1, j = 3; i <= n; i++) {
    if (i == m1) {
      cout << 1 << " ";
      continue;
    }
    if (i == m2) {
      cout << 1 << " ";
      continue;
    }
    cout << j << " ";
    j++;
  }
  return 0;
}
