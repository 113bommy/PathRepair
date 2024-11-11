#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];
int main() {
  int n, k, x, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> x;
      v[i].push_back(x);
    }
    sort(v[i].begin(), v[i].end());
  }
  int g, b, f, r, m, y, tg, tb;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      b = 1;
      g = n - 1;
    } else if (i == n - 1) {
      g = n - 2;
      b = 0;
    } else {
      g = i - 1;
      b = i + 1;
    }
    for (int j = 0; j < v[i].size() - 1; j++) {
      f = 0;
      x = y = -1;
      r = v[g].size() - 1;
      while (r >= f) {
        m = (f + r) / 2;
        if (v[g][m] > v[i][j]) {
          r = m - 1;
          x = m;
        } else {
          f = m + 1;
        }
        if (f == r - 1) {
          if (v[g][f] > v[i][j]) {
            x = f;
          } else if (v[g][r] > v[i][j]) {
            x = r;
          }
          break;
        }
      }
      f = 0;
      r = v[g].size() - 1;
      while (r >= f) {
        m = (f + r) / 2;
        if (v[g][m] > v[i][j + 1]) {
          r = m - 1;
        } else {
          f = m + 1;
          y = m;
        }
        if (f == r - 1) {
          if (v[g][r] < v[i][j + 1]) {
            y = r;
          } else if (v[g][f] < v[i][j + 1]) {
            y = f;
          }
          break;
        }
      }
      if (x == -1 || y == -1) {
        tg = 0;
      } else {
        tg = y - x + 1;
      }
      f = 0;
      x = y = -1;
      r = v[b].size() - 1;
      while (r >= f) {
        m = (f + r) / 2;
        if (v[b][m] > v[i][j]) {
          r = m - 1;
          x = m;
        } else {
          f = m + 1;
        }
        if (f == r - 1) {
          if (v[b][f] > v[i][j]) {
            x = f;
          } else if (v[b][r] > v[i][j]) {
            x = r;
          }
          break;
        }
      }
      f = 0;
      r = v[b].size() - 1;
      while (r >= f) {
        m = (f + r) / 2;
        if (v[b][m] > v[i][j + 1]) {
          r = m - 1;
        } else {
          f = m + 1;
          y = m;
        }
        if (f == r - 1) {
          if (v[b][r] < v[i][j + 1]) {
            y = r;
          } else if (v[b][f] < v[i][j + 1]) {
            y = f;
          }
          break;
        }
      }
      if (x == -1 || y == -1) {
        tb = 0;
      } else {
        tb = y - x + 1;
      }
      if (tg != tb) ans++;
    }
  }
  cout << ans;
  return 0;
}
