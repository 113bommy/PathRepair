#include <bits/stdc++.h>
using namespace std;
int inf = 2000000000;
int n, k, le, v[100050], tree[4 * 100050][2], seg[4 * 100050];
void build(int nod, int a, int b) {
  if (a == b) {
    tree[nod][0] = tree[nod][1] = v[a];
    return;
  }
  build((2 * nod), a, ((a + b) / 2)),
      build((2 * nod + 1), ((a + b) / 2) + 1, b);
  tree[nod][0] = max(tree[(2 * nod)][0], tree[(2 * nod + 1)][0]);
  tree[nod][1] = min(tree[(2 * nod)][1], tree[(2 * nod + 1)][1]);
}
pair<int, int> query(int nod, int a, int b, int i, int j) {
  if (j < a || i > b) return {-inf, inf};
  if (i <= a && j >= b) return {tree[nod][0], tree[nod][1]};
  pair<int, int> esq = query((2 * nod), a, ((a + b) / 2), i, j),
                 dir = query((2 * nod + 1), ((a + b) / 2) + 1, b, i, j), ans;
  ans.first = max(esq.first, dir.first),
  ans.second = min(esq.second, dir.second);
  return ans;
}
void upd2(int nod, int a, int b, int i, int x) {
  if (a == b) {
    seg[nod] = x;
    return;
  }
  if (i <= ((a + b) / 2))
    upd2((2 * nod), a, ((a + b) / 2), i, x);
  else
    upd2((2 * nod + 1), ((a + b) / 2) + 1, b, i, x);
  seg[nod] = min(seg[(2 * nod)], seg[(2 * nod + 1)]);
}
int query2(int nod, int a, int b, int i, int j) {
  if (j < a || i > b) return inf;
  if (i <= a && j >= b) return seg[nod];
  return min(query2((2 * nod), a, ((a + b) / 2), i, j),
             query2((2 * nod + 1), ((a + b) / 2) + 1, b, i, j));
}
int dp[100050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> le;
  for (int i = 1; i <= n; i++) cin >> v[i];
  build(1, 1, n);
  int j = 1;
  for (int i = 1; i <= n; i++) upd2(1, 0, n, i, inf);
  for (int i = 1; i <= n; i++) {
    dp[i] = inf;
    int primeiro = -1;
    for (; j <= i - le + 1; j++) {
      pair<int, int> q = query(1, 1, n, j, i);
      int maior = q.first, menor = q.second;
      if (maior - menor <= k) {
        primeiro = j;
        break;
      }
    }
    if (primeiro == -1) continue;
    dp[i] = query2(1, 0, n, primeiro - 1, i - le) + 1;
    upd2(1, 0, n, i, dp[i]);
  }
  cout << (dp[n] >= inf ? -1 : dp[n]) << "\n";
}
