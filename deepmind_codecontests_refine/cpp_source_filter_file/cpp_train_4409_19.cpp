#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  int r = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    int cntc = 0;
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '*') cntc++;
    }
    if (cntc == 1) r = i;
  }
  for (int i = 0; i < m; i++) {
    int cntr = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j][i] == '*') cntr++;
    }
    if (cntr == 1) c = i;
  }
  cout << r << ' ' << c;
}
