#include <bits/stdc++.h>
using namespace std;
bool ok;
int dfs_state[52][52];
pair<char, int> mat[105][105];
int dfs_parent[52][52];
int n, m;
bool once = 0;
void dfs(int i, int j) {
  dfs_state[i][j] = 2;
  char ano = mat[i][j].first;
  for (int l = 1; l <= 4; l++) {
    if (l == 1) {
      if ((i) >= 1 && (i) <= n && (j - 1) >= 1 && (j - 1) <= m &&
          mat[i][j - 1].first == ano) {
        if (dfs_state[i][j - 1] == 1) {
          dfs_parent[i][j - 1] = mat[i][j].second;
          dfs(i, j - 1);
        } else if (dfs_state[i][j - 1] == 2) {
          if (mat[i][j - 1].second == dfs_parent[i][j]) {
          } else {
            if (once == 0) {
              cout << "Yes" << endl;
              ok = 1;
              once = 1;
              break;
            }
          }
        }
      }
    } else if (l == 2) {
      if ((i - 1) >= 1 && (i - 1) <= n && (j) >= 1 && (j) <= m &&
          mat[i - 1][j].first == ano) {
        if (dfs_state[i - 1][j] == 1) {
          dfs_parent[i - 1][j] = mat[i][j].second;
          dfs(i - 1, j);
        } else if (dfs_state[i - 1][j] == 2) {
          if (mat[i - 1][j].second == dfs_parent[i][j]) {
          } else {
            if (once == 0) {
              cout << "Yes" << endl;
              ok = 1;
              once = 1;
              break;
            }
          }
        }
      }
    } else if (l == 3) {
      if ((i) >= 1 && (i) <= n && (j + 1) >= 1 && (j + 1) <= m &&
          mat[i][j + 1].first == ano) {
        if (dfs_state[i][j + 1] == 1) {
          dfs_parent[i][j + 1] = mat[i][j].second;
          dfs(i, j + 1);
        } else if (dfs_state[i][j + 1] == 2) {
          if (mat[i][j + 1].second == dfs_parent[i][j]) {
          } else {
            if (once == 0) {
              cout << "Yes" << endl;
              ok = 1;
              once = 1;
              break;
            }
          }
        }
      }
    } else if (l == 4) {
      if ((i + 1) >= 1 && (i + 1) <= n && (j) >= 1 && (j) <= m &&
          mat[i + 1][j].first == ano) {
        if (dfs_state[i + 1][j] == 1) {
          dfs_parent[i + 1][j] = mat[i][j].second;
          dfs(i + 1, j);
        } else if (dfs_state[i + 1][j] == 2) {
          if (mat[i + 1][j].second == dfs_parent[i][j]) {
          } else {
            if (once == 0) {
              cout << "Yes" << endl;
              ok = 1;
              once = 1;
              break;
            }
          }
        }
      }
    }
  }
  dfs_state[i][j] = 3;
}
int main() {
  int i, j;
  ok = 0;
  for (i = 1; i <= 51; i++) {
    for (j = 1; j <= 51; j++) {
      dfs_parent[i][j] = 0;
      dfs_state[i][j] = 1;
    }
  }
  scanf("%d %d", &n, &m);
  getchar();
  int k = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%c", &mat[i][j].first);
      mat[i][j].second = k++;
    }
    getchar();
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (dfs_state[i][j] == 1) {
        dfs(i, j);
      }
    }
  }
  if (ok == 0) {
    cout << "No" << endl;
  }
  return 0;
}
