#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
bool can[55][55];
bool res[105][105];
string arr[55];
int n;
bool check(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= n) return true;
  return (arr[x][y] != '.');
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    for (int j = 0; j < n; j++)
      if (arr[i][j] == 'o') v.push_back(make_pair(i, j));
  }
  for (int i = -(n - 1); i < n; i++) {
    for (int j = -(n - 1); j < n; j++) {
      if (!i && !j) continue;
      bool test = true;
      for (int k = 0; k < v.size() && test; k++) {
        int nxtx = v[k].first + i;
        int nxty = v[k].second + j;
        test &= check(nxtx, nxty);
      }
      if (test) {
        for (int k = 0; k < v.size() && test; k++) {
          int nxtx = v[k].first + i;
          int nxty = v[k].second + j;
          if (nxtx < 0 || nxty < 0 || nxtx >= n || nxty >= n) continue;
          can[nxtx][nxty] = true;
        }
        res[n + j - 1][n + i - 1] = true;
      }
    }
  }
  bool test = true;
  for (int i = 0; i < n && test; i++) {
    for (int j = 0; j < n && test; j++) {
      if (arr[i][j] == 'x' && !can[i][j]) test = false;
    }
  }
  if (!test) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < 2 * n - 1; i++) {
    string tmp = "";
    for (int j = 0; j < 2 * n - 1; j++) {
      if (i == n - 1 && j == n - 1)
        tmp += 'o';
      else if (res[i][j])
        tmp += 'x';
      else
        tmp += '.';
    }
    cout << tmp << "\n";
  }
  return 0;
}
