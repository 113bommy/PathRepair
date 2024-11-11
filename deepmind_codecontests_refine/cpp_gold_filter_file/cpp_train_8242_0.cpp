#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const int MOD = 1e9 + 7;
const long double PI = 3.1415926535898;
const long long INF = LLONG_MAX;
vector<int> r[100005], c[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  map<pair<int, int>, int> mm;
  for (int i = 1; i <= k; i++) {
    int a, b;
    cin >> a >> b;
    mm[{a, b}] = 1;
    r[a].push_back(b);
    c[b].push_back(a);
  }
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    sort(r[i].begin(), r[i].end());
  }
  for (int i = 1; i <= m; i++) {
    sort(c[i].begin(), c[i].end());
  }
  int x = 1, y = 1, dir = 1, xma = n + 1, xmi = 0, yma = m + 1, ymi = 0;
  while (xma - xmi > 1 && yma - ymi > 1) {
    if (dir == 1) {
      auto it = upper_bound(r[x].begin(), r[x].end(), y);
      if (it != r[x].end() && *it < yma) {
        for (int i = x; i < xma; i++) {
          for (int j = *it; j < yma; j++) {
            if (mm[{i, j}] == 0) {
              flag = 0;
              break;
            }
          }
          if (!flag) break;
        }
        if (!flag)
          break;
        else {
          xmi++;
          yma = *it;
          y = *it - 1;
          dir = 2;
        }
      } else {
        xmi++;
        y = yma - 1;
        dir = 2;
      }
    } else if (dir == 2) {
      auto it = upper_bound(c[y].begin(), c[y].end(), x);
      if (it != c[y].end() && *it < xma) {
        for (int i = y; i > ymi; i--) {
          for (int j = *it; j < xma; j++) {
            if (mm[{j, i}] == 0) {
              flag = 0;
              break;
            }
          }
          if (!flag) break;
        }
        if (!flag)
          break;
        else {
          yma--;
          xma = *it;
          x = *it - 1;
          dir = 3;
        }
      } else {
        yma--;
        x = xma - 1;
        dir = 3;
      }
    } else if (dir == 3) {
      auto it = upper_bound(r[x].begin(), r[x].end(), y);
      if (it != r[x].begin() && *(it - 1) > ymi) {
        it--;
        for (int i = x; i > xmi; i--) {
          for (int j = *it; j > ymi; j--) {
            if (mm[{i, j}] == 0) {
              flag = 0;
              break;
            }
          }
          if (!flag) break;
        }
        if (!flag)
          break;
        else {
          xma--;
          ymi = *it;
          y = *it + 1;
          dir = 4;
        }
      } else {
        xma--;
        y = ymi + 1;
        dir = 4;
      }
    } else {
      auto it = upper_bound(c[y].begin(), c[y].end(), x);
      if (it != c[y].begin() && *(it - 1) > xmi) {
        it--;
        for (int i = y; i < yma; i++) {
          for (int j = *it; j > xmi; j--) {
            if (mm[{j, i}] == 0) {
              flag = 0;
              break;
            }
          }
          if (!flag) break;
        }
        if (!flag)
          break;
        else {
          ymi++;
          xmi = *it;
          x = *it + 1;
          dir = 1;
        }
      } else {
        ymi++;
        x = xmi + 1;
        dir = 1;
      }
    }
  }
  if (flag)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
}
