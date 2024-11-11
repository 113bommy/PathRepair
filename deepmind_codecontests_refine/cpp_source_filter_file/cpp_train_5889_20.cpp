#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
using namespace std;
const int N = 1010;
int n, m;
int grid[N][N];
int minx[N];
int maxx[N];
int miny[N];
int maxy[N];
void solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        if (minx[i] != INT_MAX && minx[i] < j) {
          res++;
        }
        if (maxx[i] != -1 && maxx[i] > j) {
          res++;
        }
        if (miny[i] != INT_MAX && miny[j] < i) {
          res++;
        }
        if (maxy[i] != -1 && maxy[j] > i) {
          res++;
        }
      }
    }
  }
  cout << res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  fill(miny, miny + N, INT_MAX);
  fill(minx, minx + N, INT_MAX);
  fill(maxx, maxx + N, -1);
  fill(maxy, maxy + N, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 1) {
        if (i > maxy[j]) {
          maxy[j] = i;
        }
        if (i < miny[j]) {
          miny[j] = i;
        }
        if (j > maxx[i]) {
          maxx[i] = j;
        }
        if (j < minx[i]) {
          minx[i] = j;
        }
      }
    }
  }
  solve();
}
