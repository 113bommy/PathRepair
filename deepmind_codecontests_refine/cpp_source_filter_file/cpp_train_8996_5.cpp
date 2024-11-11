#include <bits/stdc++.h>
using namespace std;
template <class T>
void dumpBetween(const T& a, const T& b) {
  for (T it = a; it != b; it++) cout << *it << " ";
  cout << endl;
}
template <class T>
void dumpAll(const T& a) {
  dumpBetween((a).begin(), (a).end());
}
template <class T>
void minify(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void maxify(T& a, const T& b) {
  if (a < b) a = b;
}
struct Hill {
  long long x;
  long long y;
} hills[100008];
bool canSee(const Hill& from, const Hill& block, const Hill& to) {
  return (to.y - from.y) * (block.x - from.x) >
         (block.y - from.y) * (to.x - from.x);
}
int teams[100008][2];
int nHills, nTeams;
void readInput() {
  scanf("%d", &nHills);
  for (int i = 0; i < ((int)nHills); i++) {
    scanf("%" SCNd64 "%" SCNd64, &hills[i].x, &hills[i].y);
  }
  scanf("%d", &nTeams);
  for (int i = 0; i < ((int)nTeams); i++) {
    scanf("%d %d", &teams[i][0], &teams[i][1]);
  }
}
int parent[100008];
int depth[100008];
int curve[100008];
int curveTop;
void findParents() {
  parent[nHills - 1] = nHills - 1;
  depth[nHills - 1] = 0;
  if (nHills == 1) return;
  curve[0] = (nHills - 1);
  curve[1] = (nHills - 2);
  curveTop = 1;
  parent[nHills - 2] = nHills - 1;
  depth[nHills - 2] = 1;
  for (int i = nHills - 3; i >= 0; i--) {
    int lo = -1;
    int hi = curveTop;
    const Hill& self = hills[i];
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      const Hill& tgt = hills[curve[mid]];
      const Hill& blocker = hills[curve[mid + 1]];
      if (canSee(self, blocker, tgt))
        hi = mid;
      else
        lo = mid;
    }
    parent[i] = curve[hi];
    depth[i] = depth[curve[hi]] + 1;
    curveTop = hi + 1;
    curve[curveTop] = i;
  }
}
int xparent[100008][14];
void makeDoubling() {
  for (int i = 0; i < ((int)nHills); i++) {
    xparent[i][0] = parent[i];
  }
  for (int x = 1; x < ((int)14); x++) {
    for (int i = 0; i < ((int)nHills); i++) {
      xparent[i][x] = xparent[xparent[i][x - 1]][x - 1];
    }
  }
}
int nthParent(int a, int n) {
  while (n) {
    int x = __builtin_ctz(n);
    a = xparent[a][x];
    n = n & ~(1 << x);
  }
  return a;
}
int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  if (depth[a] > depth[b]) {
    a = nthParent(a, depth[a] - depth[b]);
  }
  assert(depth[a] == depth[b]);
  if (a == b) return a;
  for (int x = 13; x > 0; x--) {
    if (xparent[a][x] != xparent[b][x]) {
      a = xparent[a][x];
      b = xparent[b][x];
    }
  }
  assert(a != b);
  assert(parent[a] == parent[b]);
  return parent[a];
}
void solve() {
  for (int i = 0; i < ((int)nTeams); i++) {
    if (i != 0) printf(" ");
    printf("%d", lca(teams[i][0] - 1, teams[i][1] - 1) + 1);
  }
  printf("\n");
}
void tc() {
  readInput();
  findParents();
  makeDoubling();
  solve();
}
int main() { tc(); }
