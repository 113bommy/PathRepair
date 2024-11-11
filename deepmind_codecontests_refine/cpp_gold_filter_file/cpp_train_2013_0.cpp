#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793238462643l;
vector<int> e[100010];
int c[100010];
void dfs(int x, int q, vector<int> *v) {
  if (c[x] != -1) {
    return;
  }
  c[x] = q;
  v[q].push_back(x);
  for (int i = 0; i < int(e[x].size()); i++) {
    dfs(e[x][i], q ^ 1, v);
  }
}
int n;
int u[100010];
bool solve(vector<int> v[][2]) {
  for (int i = 1; i < 3; i++) {
    for (int q = 0; q < int(2); q++) {
      for (int j = 0; j < int(v[i][q].size()); j++) {
        v[0][q].push_back(v[i][q][j]);
      }
    }
  }
  if (v[0][0].size() % 3 == 2) {
    swap(v[0][0], v[0][1]);
  }
  memset(u, 0, sizeof u);
  int k = 0;
  for (int i = 0; i < int(n); i++) {
    c[i] = -1;
  }
  int ii;
  if (v[0][0].size() % 3) {
    for (ii = 0; ii < v[0][0].size(); ii++) {
      if (e[v[0][0][ii]].size() < v[0][1].size() - 1) {
        break;
      }
    }
    if (ii < v[0][0].size()) {
      u[v[0][0][ii]] = 1;
      k = 1;
      c[v[0][0][ii]] = 0;
      for (int i = 0; i < int(v[0][1].size()); i++) {
        u[v[0][1][i]] = 1;
      }
      for (int i = 0; i < int(e[v[0][0][ii]].size()); i++) {
        u[e[v[0][0][ii]][i]] = 0;
      }
      int qwe = 0;
      for (int i = 0; i < int(v[0][1].size()); i++) {
        if (u[v[0][1][i]]) {
          if (qwe < 2) {
            c[v[0][1][i]] = 0;
          } else {
            u[v[0][1][i]] = 0;
          }
          qwe++;
        }
      }
    } else {
      for (ii = 0; ii < v[0][1].size(); ii++) {
        if (e[v[0][1][ii]].size() < v[0][0].size() - 1) {
          break;
        }
      }
      int jj = ii;
      for (ii = jj + 1; ii < v[0][1].size(); ii++) {
        if (e[v[0][1][ii]].size() < v[0][0].size() - 1) {
          break;
        }
      }
      if (ii < v[0][1].size()) {
        u[v[0][1][ii]] = 1;
        u[v[0][1][jj]] = 1;
        k = 2;
        c[v[0][1][ii]] = 0;
        c[v[0][1][jj]] = 1;
        for (int i = 0; i < int(v[0][0].size()); i++) {
          u[v[0][0][i]] = 2;
        }
        for (int i = 0; i < int(e[v[0][1][ii]].size()); i++) {
          u[e[v[0][1][ii]][i]]--;
        }
        int qwe = 0;
        for (int i = 0; i < int(v[0][0].size()); i++) {
          if (u[v[0][0][i]] == 2) {
            if (qwe < 2) {
              c[v[0][0][i]] = 0;
            } else {
              u[v[0][0][i]]--;
            }
            qwe++;
          }
        }
        for (int i = 0; i < int(e[v[0][1][jj]].size()); i++) {
          u[e[v[0][1][jj]][i]]--;
        }
        qwe = 0;
        for (int i = 0; i < int(v[0][0].size()); i++) {
          if (u[v[0][0][i]] && c[v[0][0][i]] == -1) {
            if (qwe < 2) {
              c[v[0][0][i]] = 1;
            } else {
              u[v[0][0][i]]--;
            }
            qwe++;
          }
        }
      } else {
        return 0;
      }
    }
  }
  int l = 0;
  for (int i = 0; i < int(v[0][0].size()); i++) {
    if (!u[v[0][0][i]]) {
      c[v[0][0][i]] = k;
      l++;
      if (l == 3) {
        k++;
        l = 0;
      }
    }
  }
  for (int i = 0; i < int(v[0][1].size()); i++) {
    if (!u[v[0][1][i]]) {
      c[v[0][1][i]] = k;
      l++;
      if (l == 3) {
        k++;
        l = 0;
      }
    }
  }
  puts("YES");
  for (int i = 0; i < int(n); i++) {
    printf("%d", c[i] + 1);
    if (i < n - 1) {
      printf(" ");
    }
  }
  puts("");
  return 1;
}
vector<int> v[100010][2], w[3][2];
int main() {
  int m;
  cin >> n >> m;
  for (int i = 0; i < int(m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  memset(c, -1, sizeof c);
  int k = 0;
  for (int i = 0; i < int(n); i++) {
    dfs(i, 0, v[k]);
    if (v[k][0].size()) {
      k++;
    }
  }
  int ii;
  for (ii = 0; ii < k; ii++) {
    if ((v[ii][0].size() - v[ii][1].size()) % 3) {
      break;
    }
  }
  if (ii < k) {
    swap(v[0][0], v[ii][0]);
    swap(v[0][1], v[ii][1]);
  }
  for (ii = 1; ii < k; ii++) {
    if ((v[ii][0].size() - v[ii][1].size()) % 3) {
      break;
    }
  }
  if (ii < k) {
    swap(v[1][0], v[ii][0]);
    swap(v[1][1], v[ii][1]);
  }
  for (int i = 3; i < k; i++) {
    for (int q = 0; q < int(2); q++) {
      for (int j = 0; j < int(v[i][q].size()); j++) {
        v[2][q].push_back(v[i][q][j]);
      }
    }
  }
  bool b[3];
  int x[3][2];
  for (int i = 0; i < int(3); i++) {
    for (int q = 0; q < int(2); q++) {
      x[i][q] = v[i][q].size() % 3;
    }
    b[i] = (x[i][0] != x[i][1]);
  }
  for (int mask = 0; mask < int(4); mask++) {
    bool I[3];
    for (int i = 0; i < int(3); i++) {
      I[i] = (mask & (1 << i));
    }
    for (int i = 0; i < int(3); i++) {
      for (int q = 0; q < int(2); q++) {
        w[i][q] = v[i][q ^ I[i]];
      }
    }
    if (solve(w)) {
      return 0;
    }
  }
  puts("NO");
  return 0;
}
