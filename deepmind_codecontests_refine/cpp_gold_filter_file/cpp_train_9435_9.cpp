#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid;
vector<int> flip(vector<int> v, int t) {
  int val, ad = 0;
  int c = t;
  vector<int> v2;
  v2.resize(v.size());
  if (v.size() & 1) val = v.back(), ad = t & 1, v.pop_back();
  for (int i = 0; i < v.size() / 2; i++) {
    if ((c & 1) ^ ad) {
      v2[i + ad] = v[v.size() / 2 - 1 - i];
      v2[v.size() - 1 - i + ad] = v[v.size() / 2 + i];
    } else {
      v2[i + ad] = v[v.size() / 2 + i];
      v2[v.size() - 1 - i + ad] = v[v.size() / 2 - 1 - i];
    }
    c++;
  }
  if (ad)
    v2[0] = val;
  else if (v2.size() & 1)
    v2[v2.size() - 1] = val;
  return v2;
}
int main() {
  cin >> n >> m;
  grid.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      grid[i].push_back(i * m + j + 1);
    }
  }
  if (n == 1 && m == 1)
    cout << "YES\n1" << endl;
  else if (n < 3 && m < 3)
    cout << "NO" << endl;
  else if (n == 3 && m == 3)
    cout << "YES\n5 1 9\n3 8 4\n7 6 2" << endl;
  else if (m >= 4) {
    for (int i = 0; i < n; i++) {
      grid[i] = flip(grid[i], i & 1);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << grid[i][j] << " ";
      cout << endl;
    }
  } else if (n >= 4) {
    for (int i = 0; i < m; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) v.push_back(grid[j][i]);
      v = flip(v, i & 1);
      for (int j = 0; j < n; j++) grid[j][i] = v[j];
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << grid[i][j] << " ";
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
