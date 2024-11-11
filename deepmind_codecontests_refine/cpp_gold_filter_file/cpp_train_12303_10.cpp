#include <bits/stdc++.h>
using namespace std;
void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);
const long long mod = 1e9 + 7;
const double PI = acos(-1);
int n, i, j, k, t;
int m[55][55];
int dx[] = {2, 1, 0};
int dy[] = {0, 1, 2};
int par[55 * 55];
int in;
int get_set(int v) {
  if (v == par[v]) return v;
  return par[v] = get_set(par[v]);
}
void union_set(int a, int b) {
  a = get_set(a);
  b = get_set(b);
  if (a != b) {
    par[b] = a;
  }
}
int main() {
  cin >> n;
  memset(m, -1, sizeof m);
  queue<pair<int, int> > q;
  m[1][1] = 1;
  m[n][n] = 0;
  q.push({1, 1});
  while (!q.empty()) {
    pair<int, int> tmp = q.front();
    q.pop();
    for (int i = 0; i < 3; ++i) {
      int xx = tmp.first + dx[i];
      int yy = tmp.second + dy[i];
      if (m[xx][yy] != -1 || xx > n || yy > n) continue;
      cout << "? " << tmp.first << " " << tmp.second << " " << xx << " " << yy
           << endl;
      cin >> in;
      if (in) {
        m[xx][yy] = m[tmp.first][tmp.second];
      } else {
        m[xx][yy] = !m[tmp.first][tmp.second];
      }
      q.push({xx, yy});
    }
  }
  m[1][2] = 2;
  q.push({1, 2});
  while (!q.empty()) {
    pair<int, int> tmp = q.front();
    q.pop();
    for (int i = 0; i < 3; ++i) {
      int xx = tmp.first + dx[i];
      int yy = tmp.second + dy[i];
      if (m[xx][yy] != -1 || xx > n || yy > n) continue;
      cout << "? " << tmp.first << " " << tmp.second << " " << xx << " " << yy
           << endl;
      cin >> in;
      if (in) {
        m[xx][yy] = m[tmp.first][tmp.second];
      } else {
        m[xx][yy] = !(m[tmp.first][tmp.second] - 2) + 2;
      }
      q.push({xx, yy});
    }
  }
  cout << "? 2 1 3 2" << endl;
  cin >> in;
  if (in) {
    m[2][1] = m[3][2];
  } else {
    m[2][1] = !(m[3][2] - 2) + 2;
  }
  q.push({2, 1});
  while (!q.empty()) {
    pair<int, int> tmp = q.front();
    q.pop();
    for (int i = 0; i < 3; ++i) {
      int xx = tmp.first + dx[i];
      int yy = tmp.second + dy[i];
      if (m[xx][yy] != -1 || xx > n || yy > n) continue;
      cout << "? " << tmp.first << " " << tmp.second << " " << xx << " " << yy
           << endl;
      cin >> in;
      if (in) {
        m[xx][yy] = m[tmp.first][tmp.second];
      } else {
        m[xx][yy] = !(m[tmp.first][tmp.second] - 2) + 2;
      }
      q.push({xx, yy});
    }
  }
  int cnt = 0;
  int x = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= n; ++j) {
      if (i + j < 5 || m[i][j] > 1 || m[i][j] < 0) continue;
      if (i > 2) {
        bool bisa = false;
        bisa = bisa || ((m[i][j] == m[i - 1][j - 1]) ==
                        (m[i - 2][j - 1] == m[i][j - 1]));
        bisa = bisa || ((m[i][j] == m[i - 1][j - 1]) ==
                        (m[i - 2][j - 1] == m[i - 1][j]));
        bisa = bisa ||
               ((m[i][j] == m[i - 2][j]) == (m[i - 2][j - 1] == m[i - 1][j]));
        if (bisa) {
          cout << "? " << i - 2 << " " << j - 1 << " " << i << " " << j << endl;
          cin >> in;
          x = in == (m[i - 2][j - 1] == 2) ? m[i][j] : !m[i][j];
          cnt++;
          break;
        }
      }
      if (j > 2) {
        bool bisa = false;
        bisa = bisa || ((m[i][j] == m[i - 1][j - 1]) ==
                        (m[i - 1][j - 2] == m[i - 1][j]));
        bisa = bisa || ((m[i][j] == m[i - 1][j - 1]) ==
                        (m[i - 1][j - 2] == m[i][j - 1]));
        bisa = bisa ||
               ((m[i][j] == m[i][j - 2]) == (m[i - 1][j - 2] == m[i][j - 1]));
        if (bisa) {
          cout << "? " << i - 1 << " " << j - 2 << " " << i << " " << j << endl;
          cin >> in;
          x = in == (m[i - 1][j - 2] == 2) ? m[i][j] : !m[i][j];
          cnt++;
          break;
        }
      }
    }
    if (cnt) break;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (m[i][j] == 2) {
        m[i][j] = x;
      } else if (m[i][j] == 3) {
        m[i][j] = !x;
      }
    }
  }
  puts("!");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d", m[i][j]);
    }
    puts("");
  }
  return 0;
}
void printArray(const int *a, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  puts("");
}
void printArray(const vector<int> &arr) {
  for (int x : arr) {
    printf("%d ", x);
  }
  puts("");
}
