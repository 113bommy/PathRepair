#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
char g[MAXN][MAXN];
int size = 2;
void add_edge(int u, int v) { g[u][v] = g[v][u] = 'Y'; }
void add_chain(int u, int v, int len) {
  int cur = u;
  for (int i = 0; i < (int)(len); ++i) {
    int next = size++;
    add_edge(cur, next);
    cur = next;
  }
  add_edge(cur, v);
}
int main(int argc, char **argv) {
  int k;
  scanf("%d", &k);
  for (int i = 0; i < (int)(MAXN); ++i) {
    for (int j = 0; j < (int)(MAXN); ++j) {
      g[i][j] = 'N';
    }
  }
  int len = 30;
  vector<int> prev;
  prev.push_back(0);
  for (int j = 0; j < (int)(30); ++j) {
    if (k & 1) {
      for (int j = 0; j < (int)(prev.size()); ++j) {
        add_chain(prev[j], 1, len);
      }
    }
    int v1 = size++;
    int v2 = size++;
    for (int j = 0; j < (int)(prev.size()); ++j) {
      add_edge(prev[j], v1);
      add_edge(prev[j], v2);
    }
    prev.clear();
    prev.push_back(v1);
    prev.push_back(v2);
    --len;
    k >>= 1;
  }
  printf("%d\n", size);
  for (int i = 0; i < (int)(size); ++i) {
    for (int j = 0; j < (int)(size); ++j) {
      printf("%c", g[i][j]);
    }
    printf("\n");
  }
  return 0;
}
