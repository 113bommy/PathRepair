#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e2 + 5;
char mat[N][N];
int n, m;
void dfs(int i, int j, set<int>& x, set<int>& y) {
  if (!x.count(i)) {
    x.insert(i);
    for (int q = 0; q < m; ++q) {
      if (mat[i][q] == '#') dfs(i, q, x, y);
    }
  }
  if (!y.count(j)) {
    y.insert(j);
    for (int k = 0; k < n; ++k)
      if (mat[k][j] == '#') dfs(k, j, x, y);
  }
}
bool check(int i, int j, set<int>& x, set<int>& y) {
  dfs(i, j, x, y);
  for (int k : x) {
    for (int q : y) {
      if (mat[k][q] != '#') return false;
    }
  }
  return true;
}
bool solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    scanf("%*c");
    for (int j = 0; j < m; ++j) {
      scanf("%c", &mat[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '#') {
        set<int> x, y;
        if (check(i, j, x, y)) {
          for (int k : x) {
            for (int q : y) {
              mat[k][q] = '.';
            }
          }
        } else {
          puts("No");
          return 0;
        }
      }
    }
  }
  puts("Yes");
  return 0;
}
int main() {
  while (solve())
    ;
  return 0;
}
