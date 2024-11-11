#include <bits/stdc++.h>
using namespace std;
bool locked[(1 << 7) - 1];
vector<int> adjs[(1 << 7) - 1];
int path1[7 * 2], path2[7 * 2];
int q;
int expand(int node, int parent, int depth, int maxDepth, int* path,
           bool lockAll) {
  if (depth == maxDepth) return -2;
  path[depth] = node;
  if (lockAll) locked[node] = true;
  if (adjs[node].empty()) {
    if (q == 16) {
      printf("! %d\n", node + 1);
      fflush(stdout);
      return -1;
    }
    printf("? %d\n", node + 1);
    fflush(stdout);
    q++;
    int k;
    scanf("%d", &k);
    if (!k) exit(0);
    for (int i = 0; i < k; i++) {
      int t;
      scanf("%d", &t);
      adjs[node].push_back(t - 1);
    }
    if (k == 1) return depth;
    if (k == 2) {
      printf("! %d\n", node + 1);
      fflush(stdout);
      return -1;
    }
  }
  for (int adj : adjs[node]) {
    if (adj != parent && !locked[adj]) {
      int res = expand(adj, node, depth + 1, maxDepth, path, lockAll);
      if (res != -2) return res;
    }
  }
  return -2;
}
int expandNode(int node, int maxDepth, int* path, bool lockAll) {
  return expand(node, -1, 0, maxDepth, path, lockAll);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int h;
    scanf("%d", &h);
    if (!h) exit(0);
    memset(locked, false, sizeof(locked));
    for (int i = 0; i < (1 << h) - 1; i++) adjs[i].clear();
    q = 0;
    int d1 = expandNode(0, 2 * h, path1, true);
    if (d1 < 0) continue;
    int d2 = expandNode(0, 2 * h, path2, true);
    if (d2 < 0) continue;
    int curr = 0, i = 0;
    while (d1 < d2) {
      curr = path2[++i];
      d1++;
      d2--;
    }
    while (d2 < d1) {
      curr = path1[++i];
      d1--;
      d2++;
    }
    while ((d2 = expandNode(curr, h - d1, path1, false)) >= 0) {
      i = 0;
      while (d1 < d2) {
        curr = path1[++i];
        d1++;
        d2--;
      }
      locked[path1[i - 1]] = locked[path1[i + 1]] = true;
    }
  }
  return 0;
}
