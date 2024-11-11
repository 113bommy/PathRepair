#include <bits/stdc++.h>
using namespace std;
char a[100][100];
char b[100][100];
int n, m, k;
int kek;
vector<pair<int, int> > z[3000];
pair<int, int> z1[3000];
int l = 0;
void sea(int i, int j) {
  a[i][j] = '*';
  kek++;
  if (a[i - 1][j] == '.' && i - 1 >= 0)
    sea(i - 1, j), z[l].push_back(make_pair(i - 1, j));
  if (a[i][j - 1] == '.' && j - 1 >= 0)
    sea(i, j - 1), z[l].push_back(make_pair(i, j - 1));
  if (a[i][j + 1] == '.' && j + 1 < m)
    sea(i, j + 1), z[l].push_back(make_pair(i, j + 1));
  if (a[i + 1][j] == '.' && i + 1 < n)
    sea(i + 1, j), z[l].push_back(make_pair(i + 1, j));
  return;
}
void seak(int i, int j) {
  a[i][j] = '*';
  if (a[i - 1][j] == '.' && i - 1 >= 0) seak(i - 1, j);
  if (a[i][j - 1] == '.' && j - 1 >= 0) seak(i, j - 1);
  if (a[i][j + 1] == '.' && j + 1 < m) seak(i, j + 1);
  if (a[i + 1][j] == '.' && i + 1 < n) seak(i + 1, j);
  return;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> a[i][j], b[i][j] = a[i][j];
  }
  for (int i = 0; i < n; i++) {
    if (a[i][0] == '.') seak(i, 0);
  }
  for (int i = 0; i < n; i++) {
    if (a[i][m - 1] == '.') seak(i, m - 1);
  }
  for (int j = 0; j < m; j++) {
    if (a[0][j] == '.') seak(0, j);
  }
  for (int j = 0; j < m; j++) {
    if (a[n - 1][j] == '.') seak(n - 1, j);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        kek = 0;
        z[l].push_back(make_pair(i, j));
        sea(i, j);
        z1[l].first = kek;
        z1[l].second = l;
        l++;
      }
    }
  }
  sort(z1, z1 + l);
  int ans = 0;
  int q = 0;
  while (k < l) {
    for (int i = 0; i < z[z1[q].second].size(); i++) {
      b[z[z1[q].second][i].first][z[z1[q].second][i].second] = '*';
      ans++;
    }
    q++;
    l--;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << b[i][j];
    }
    cout << endl;
  }
  return 0;
}
