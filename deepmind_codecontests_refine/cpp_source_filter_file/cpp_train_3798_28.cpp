#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 18;
struct query {
  int x1, x2, y1, y2;
  int id;
  void read(int i) {
    id = i;
    scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
  }
  void rev() {
    swap(x1, y1);
    swap(x2, y2);
  }
};
int N, M, K, Q;
int X[MAXN], Y[MAXN];
query queries[MAXN];
int tree[2 * MAXN];
bool ans[MAXN];
vector<int> adj[MAXN], qadj[MAXN];
void update(int x, int v) {
  tree[x += MAXN] = v;
  while (x /= 2) {
    tree[x] = min(tree[2 * x], tree[2 * x + 1]);
  }
}
int query(int a, int b, int cur = 1, int l = 0, int r = MAXN) {
  if (r <= a || b <= l) {
    return MAXN;
  }
  if (a <= l && r <= b) {
    return tree[cur];
  }
  int mid = (l + r) / 2;
  return min(query(a, b, 2 * cur, l, mid), query(a, b, 2 * cur + 1, mid, r));
}
void go() {
  memset((tree), (0), sizeof(tree));
  for (int i = 1; i <= K; i++) {
    adj[X[i]].push_back(Y[i]);
  }
  for (int i = 1; i <= Q; i++) {
    qadj[queries[i].x2].push_back(i);
  }
  for (int i = 1; i <= N; i++) {
    for (int y : adj[i]) {
      update(y, i);
    }
    for (int q : qadj[i]) {
      if (query(queries[q].y1, queries[q].y2 + 1) >= queries[q].x1) {
        ans[q] = true;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    adj[i].clear();
    qadj[i].clear();
  }
}
int main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
  }
  scanf("%d %d %d %d", &N, &M, &K, &Q);
  N = max(N, M);
  for (int i = 1; i <= K; i++) {
    scanf("%d %d", &X[i], &Y[i]);
  }
  for (int i = 1; i <= Q; i++) {
    queries[i].read(i);
  }
  go();
  for (int i = 1; i <= K; i++) {
    swap(X[i], Y[i]);
  }
  for (int i = 1; i <= Q; i++) {
    queries[i].rev();
  }
  go();
  for (int i = 1; i <= Q; i++) {
    puts(ans[i] ? "YES" : "NO");
  }
}
