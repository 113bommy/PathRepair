#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int n, m;
int res = 0;
int tmp = 0;
int cnt = 0;
pair<pair<int, int>, int> aa[222222];
int it;
int moved[55];
void quayxe() {
  it++;
  tmp = 0;
  for (int i = 2; i <= n; i++) {
    if (a[2][i] && a[2][i - 1] == 0 && moved[a[2][i]] != it) {
      tmp = 1;
      moved[a[2][i]] = it;
      aa[++cnt].first.first = a[2][i];
      aa[cnt].first.second = 2;
      aa[cnt].second = i - 1;
      a[2][i - 1] = a[2][i];
      a[2][i] = 0;
    }
  }
  if (a[3][n] && a[2][n] == 0 && moved[a[3][n]] != it) {
    tmp = 1;
    moved[a[3][n]] = it;
    aa[++cnt].first.first = a[3][n];
    aa[cnt].first.second = 2;
    aa[cnt].second = n;
    a[2][n] = a[3][n];
    a[3][n] = 0;
  }
  for (int i = n - 1; i >= 1; i--) {
    tmp = 1;
    if (a[3][i] && a[3][i + 1] == 0 && moved[a[3][i]] != it) {
      moved[a[3][i]] = it;
      aa[++cnt].first.first = a[3][i];
      aa[cnt].first.second = 3;
      aa[cnt].second = i + 1;
      a[3][i + 1] = a[3][i];
      a[3][i] = 0;
    }
  }
  if (a[2][1] && a[3][1] == 0 && moved[a[2][1]] != it) {
    tmp = 1;
    moved[a[2][1]] = it;
    aa[++cnt].first.first = a[2][1];
    aa[cnt].first.second = 3;
    aa[cnt].second = 1;
    a[3][1] = a[2][1];
    a[2][1] = 0;
  }
}
void doxe() {
  for (int i = 1; i <= n; i++) {
    if (a[2][i] == a[1][i] && a[2][i]) {
      aa[++cnt].first.first = a[2][i];
      aa[cnt].first.second = 1;
      aa[cnt].second = i;
      a[2][i] = 0;
    }
    if (a[3][i] == a[4][i] && a[3][i]) {
      aa[++cnt].first.first = a[3][i];
      aa[cnt].first.second = 4;
      aa[cnt].second = i;
      a[3][i] = 0;
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  doxe();
  int k = 20000;
  while (k--) {
    quayxe();
    if (tmp == 0) break;
    doxe();
  }
  if (cnt == 0) {
    cout << -1;
    exit(0);
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++)
    cout << aa[i].first.first << " " << aa[i].first.second << " "
         << aa[i].second << endl;
}
