#include <bits/stdc++.h>
using namespace std;
int n, root;
vector<int> sons[100001];
int value[100001];
int depth[100001];
double leftmost[100001];
double rightmost[100001];
int z = 0;
struct data {
  int key;
  double ans;
  int depth;
  data() {}
  data(int _k, double _a, int _d) {
    key = _k;
    ans = _a;
    depth = _d;
  }
  bool operator<(const data& u) const { return key < u.key; }
} D[200001];
void dfs1(int cur, int dep) {
  depth[cur] = dep;
  if (sons[cur].size() > 0) {
    if (value[sons[cur][0]] > value[sons[cur][1]])
      swap(sons[cur][0], sons[cur][1]);
    dfs1(sons[cur][0], dep + 1);
    dfs1(sons[cur][1], dep + 1);
    leftmost[cur] = leftmost[sons[cur][0]];
    rightmost[cur] = rightmost[sons[cur][1]];
  } else {
    leftmost[cur] = value[cur];
    rightmost[cur] = value[cur];
  }
}
void dfs2(int cur, double carry) {
  if (sons[cur].size() > 0) {
    dfs2(sons[cur][0], carry + leftmost[sons[cur][1]]);
    dfs2(sons[cur][1], carry + rightmost[sons[cur][0]]);
  }
  if (cur == 1)
    D[++z] = data(value[cur], -1, depth[cur]);
  else
    D[++z] = data(value[cur], carry / (double)depth[cur], depth[cur]);
}
int main() {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int f;
    cin >> f;
    if (f != -1)
      sons[f].push_back(i);
    else
      root = i;
    cin >> value[i];
  }
  dfs1(root, 0);
  dfs2(root, 0.0);
  D[++z] = data(-1000000001, -1, -1);
  D[++z] = data(1000000001, -1, -1);
  sort(D + 1, D + 1 + z);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int want;
    cin >> want;
    int L = 1, R = z, M;
    while (R - L > 1) {
      M = (L + R) >> 1;
      if (D[M].key < want)
        L = M;
      else
        R = M;
    }
    if (D[L].depth > D[R].depth)
      cout << D[L].ans << endl;
    else
      cout << D[R].ans << endl;
  }
  return 0;
}
