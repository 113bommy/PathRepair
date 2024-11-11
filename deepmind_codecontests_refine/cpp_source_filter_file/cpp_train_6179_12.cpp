#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n, m;
int isValid(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}
int black(int x, int y) {
  int found = false;
  for (int i = x - 3; i <= x + 3; i++) {
    for (int j = y - 3; j <= y + 3; j++) {
      if (isValid(i, j)) {
        int ok = true;
        for (int k = i; k < i + 3; k++) {
          for (int l = j; l < j + 3; l++) {
            if (!isValid(k, l)) {
              ok = false;
              break;
            }
            if (a[k][l] != 1) {
              ok = false;
              break;
            }
          }
        }
        if (ok) {
          found = true;
          break;
        }
      }
    }
  }
  if (found)
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m;
  vector<pair<int, int> > moves;
  for (int i = 0; i < m; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    t1--;
    t2--;
    moves.push_back(make_pair(t1, t2));
  }
  int ans = -1;
  for (int i = 0; i < m; i++) {
    int t1 = moves[i].first;
    int t2 = moves[i].second;
    a[t1][t2] = 1;
    if (black(t1, t2)) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
