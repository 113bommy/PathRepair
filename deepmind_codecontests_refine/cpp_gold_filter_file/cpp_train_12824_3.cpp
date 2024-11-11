#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  unordered_map<long long int, vector<long long int>> mm;
  unordered_map<int, bool> map1;
  unordered_map<int, bool> map2;
  unordered_map<int, bool> map3;
  for (long long int i = 1; i <= n; i++) {
    map1[i] = false;
    map2[i] = false;
    map3[i] = false;
  }
  for (long long int i = 0; i < m; i++) {
    long long int x, y;
    cin >> x >> y;
    mm[x].push_back(y);
    mm[y].push_back(x);
    if (x == 1) {
      map1[y] = true;
    }
    if (y == 1) {
      map1[x] = true;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    sort(mm[i].begin(), mm[i].end());
  }
  unordered_map<long long int, bool> m1;
  unordered_map<long long int, bool> m2;
  unordered_map<long long int, bool> m3;
  for (long long int i = 1; i <= n; i++) {
    m1[i] = false;
    m2[i] = false;
    m3[i] = false;
  }
  m1[1] = true;
  for (long long int i = 2; i <= n; i++) {
    if (map1[i] == false) {
      m1[i] = true;
    }
  }
  long long int ns;
  for (long long int i = 1; i <= n; i++) {
    if (m1[i] == false) {
      ns = i;
      break;
    }
  }
  for (int i = 0; i < mm[ns].size(); i++) {
    map2[mm[ns][i]] = true;
  }
  m2[ns] = true;
  for (long long int i = 1; i <= n; i++) {
    if (map2[i] == false && ns != i) {
      m2[i] = true;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    if (m1[i] == false && m2[i] == false) {
      ns = i;
      break;
    }
  }
  for (int i = 0; i < mm[ns].size(); i++) {
    map3[mm[ns][i]] = true;
  }
  m3[ns] = true;
  for (long long int i = 1; i <= n; i++) {
    if (map3[i] == false && ns != i) {
      m3[i] = true;
    }
  }
  bool ans = true;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j < mm[i].size(); j++) {
      long long int u = i;
      long long int v = mm[i][j];
      if ((m1[u] && m1[v]) || (m2[u] && m2[v]) || (m3[u] && m3[v])) {
        ans = false;
        break;
      }
    }
  }
  long long int s1 = 0;
  long long int s2 = 0;
  long long int s3 = 0;
  for (long long int i = 1; i <= n; i++) {
    if (m1[i]) {
      s1++;
    } else if (m2[i]) {
      s2++;
    } else if (m3[i]) {
      s3++;
    }
  }
  if ((s1 + s2 + s3) != n) {
    ans = false;
  }
  if ((s1 * s2 + s2 * s3 + s3 * s1) != m) {
    ans = false;
  }
  if (s1 == 0 || s2 == 0 || s3 == 0) {
    ans = false;
  }
  if (ans == false) {
    cout << -1 << endl;
  } else {
    for (long long int i = 1; i <= n; i++) {
      if (m1[i]) {
        cout << 1 << " ";
      } else if (m2[i]) {
        cout << 2 << " ";
      } else {
        cout << 3 << " ";
      }
    }
  }
  return 0;
}
