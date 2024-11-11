#include <bits/stdc++.h>
using namespace std;
const int maxn = 2016;
vector<int> g[2][maxn];
vector<int> g2[2][maxn];
vector<int> gr[2][maxn];
int n;
int neg(int first) {
  if (first < n) {
    return first + n;
  } else {
    return first - n;
  }
}
void add(int f, int first, int second) {
  g[f][first].push_back(second);
  gr[f][second].push_back(first);
}
vector<int> was;
vector<int> ls[2];
vector<int> col[2];
vector<int> who[2][maxn];
int C[2];
void dfs1(int f, int v) {
  was[v] = 1;
  for (int e : g[f][v])
    if (!was[e]) {
      dfs1(f, e);
    }
  ls[f].push_back(v);
}
void dfs2(int f, int v, int c) {
  col[f][v] = c;
  who[f][c].push_back(v);
  for (int e : gr[f][v])
    if (col[f][e] == -1) {
      dfs2(f, e, c);
    }
}
void compress(int f) {
  was = vector<int>(2 * n, 0);
  for (int i = 0; i < 2 * n; i++) {
    if (was[i] == 0) {
      dfs1(f, i);
    }
  }
  col[f] = vector<int>(2 * n, -1);
  reverse((ls[f]).begin(), (ls[f]).end());
  C[f] = 0;
  for (int v : ls[f]) {
    if (col[f][v] == -1) {
      dfs2(f, v, ++C[f]);
    }
  }
  for (int v = 0; v < 2 * n; v++) {
    for (int e : g[f][v]) {
      g2[f][col[f][v]].push_back(col[f][e]);
    }
  }
  for (int i = 1; i <= C[f]; i++) {
    {
      sort((g2[f][i]).begin(), (g2[f][i]).end()),
          g2[f][i].resize(unique((g2[f][i]).begin(), (g2[f][i]).end()) -
                          g2[f][i].begin());
    };
  }
}
vector<unsigned long long> path[2][maxn];
int K;
void SET(vector<unsigned long long>& a, int first) {
  a[first >> 6] |= ((unsigned long long)1) << (first & 63);
}
bool ISONE(vector<unsigned long long>& a, int first) {
  return (a[first >> 6] >> (first & 63)) & 1;
}
void OR(vector<unsigned long long>& a, vector<unsigned long long>& b,
        int first) {
  for (int i = first >> 6; i < K; i++) {
    a[i] |= b[i];
  }
}
void calcpath(int f) {
  K = (C[f] + 1) / 64 + 2;
  for (int i = 1; i <= C[f]; i++) {
    path[f][i] = vector<unsigned long long>(K, 0);
  }
  for (int v = C[f]; v >= 1; v--) {
    SET(path[f][v], v);
    for (int e : g2[f][v]) {
      OR(path[f][v], path[f][e], e);
    }
  }
}
void printsol(int f) {
  for (int i = 0; i < n; i++) {
    if (col[f][i] < col[f][i + n]) {
      printf("0 ");
    } else {
      printf("1 ");
    }
  }
}
vector<pair<int, int>> lse[2];
bool can1(int f, int first) {
  return !ISONE(path[f][col[f][first]], col[f][neg(first)]);
}
bool can2(int f, int x1, int x2) {
  for (int i = 0; i < n; i++) {
    int val1 = -1;
    if (ISONE(path[f][col[f][x1]], col[f][i])) {
      val1 = 1;
    }
    if (ISONE(path[f][col[f][x1]], col[f][i + n])) {
      val1 = 0;
    }
    int val2 = -1;
    if (ISONE(path[f][col[f][x2]], col[f][i])) {
      val2 = 1;
    }
    if (ISONE(path[f][col[f][x2]], col[f][i + n])) {
      val2 = 0;
    }
    if (val1 != -1 && val2 != -1) {
      if (val1 != val2) {
        return false;
      }
    }
  }
  return true;
}
bool canprint(int f, int x1, int x2) {
  for (int i = 0; i < n; i++) {
    int val1 = -1;
    if (ISONE(path[f][col[f][x1]], col[f][i])) {
      val1 = 1;
    }
    if (ISONE(path[f][col[f][x1]], col[f][i + n])) {
      val1 = 0;
    }
    int val2 = -1;
    if (ISONE(path[f][col[f][x2]], col[f][i])) {
      val2 = 1;
    }
    if (ISONE(path[f][col[f][x2]], col[f][i + n])) {
      val2 = 0;
    }
    if (val1 == -1) {
      if (val2 == -1) {
        if (col[f][i] < col[f][i + n]) {
          printf("0 ");
        } else {
          printf("1 ");
        }
      } else {
        printf("%d ", val2);
      }
      continue;
    }
    if (val2 == -1) {
      if (val1 == -1) {
        if (col[f][i] < col[f][i + n]) {
          printf("0 ");
        } else {
          printf("1 ");
        }
      } else {
        printf("%d ", val1);
      }
      continue;
    }
    printf("%d ", val1);
  }
  return false;
}
void can(int f1, int f2) {
  for (auto p : lse[f1]) {
    int v1 = p.first;
    int v2 = p.second;
    if (can1(f2, neg(v1)) && can1(f2, neg(v1))) {
      if (can2(f2, neg(v1), neg(v2))) {
        canprint(f2, neg(v1), neg(v2));
        exit(0);
      }
    }
  }
}
int main() {
  vector<int> m(2, 0);
  scanf("%d %d %d", &n, &m[0], &m[1]);
  for (int f = 0; f < 2; f++) {
    for (int i = 0; i < m[f]; i++) {
      int first, second;
      scanf("%d %d", &first, &second);
      if (first > 0) {
        first = first - 1;
      } else {
        first = -first - 1 + n;
      }
      if (second > 0) {
        second = second - 1;
      } else {
        second = -second - 1 + n;
      }
      lse[f].push_back(make_pair(first, second));
      add(f, neg(first), second);
      add(f, neg(second), first);
    }
    compress(f);
    calcpath(f);
  }
  vector<bool> nosol(2, false);
  for (int f = 0; f < 2; f++) {
    for (int i = 0; i < n; i++) {
      if (ISONE(path[f][col[f][i]], col[f][i + n]) &&
          ISONE(path[f][col[f][i + n]], col[f][i])) {
        nosol[f] = true;
      }
    }
  }
  if (nosol[0] && nosol[1]) {
    printf("SIMILAR\n");
    return 0;
  }
  if (nosol[0] && !nosol[1]) {
    printsol(1);
    return 0;
  }
  if (!nosol[0] && nosol[1]) {
    printsol(0);
    return 0;
  }
  can(0, 1);
  can(1, 0);
  printf("SIMILAR\n");
  return 0;
}
