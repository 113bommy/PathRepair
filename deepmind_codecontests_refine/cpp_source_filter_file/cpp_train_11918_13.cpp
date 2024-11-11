#include <bits/stdc++.h>
using namespace std;
long long D[200005], H[200005], sumd[200005];
pair<int, int> ANS, tree[1000006];
long long ans, n, m, x, y, l, r;
long long dist(int x, int y) { return sumd[y - 1] - sumd[x - 1]; }
void check(int x, int y) {
  int P = (H[x] + H[y]) * 2 + dist(x, y);
  if (x == y) P = H[x] * 2;
  if (ans < P) {
    ANS = {x, y};
    ans = P;
  }
}
pair<int, int> go(pair<int, int> A, pair<int, int> B) {
  ANS = {0, 0};
  if (A == ANS) return B;
  if (B == ANS) return A;
  ans = 0;
  check(A.first, B.first);
  check(A.first, B.second);
  check(A.second, B.first);
  check(A.second, B.second);
  check(A.first, A.second);
  check(B.first, B.second);
  return ANS;
}
void upd(int node, int tl, int tr, int pos) {
  if (tl == tr) {
    tree[node] = {pos, pos};
    return;
  }
  int mid = (tl + tr) / 2;
  if (pos <= mid)
    upd(node * 2, tl, mid, pos);
  else
    upd(node * 2 + 1, mid + 1, tr, pos);
  tree[node] = go(tree[node * 2], tree[node * 2 + 1]);
}
pair<int, int> get(int node, int tl, int tr, int l, int r) {
  if (tl > r || tr < l) return {0, 0};
  if (l <= tl && tr <= r) return tree[node];
  int mid = (tl + tr) / 2;
  pair<int, int> x = get(node * 2, tl, mid, l, r);
  pair<int, int> y = get(node * 2 + 1, mid + 1, tr, l, r);
  return go(x, y);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> D[i], D[i + n] = D[i];
  for (int i = 1; i <= n; i++) cin >> H[i], H[i + n] = H[i];
  for (int i = 1; i <= 2 * n; i++) sumd[i] = D[i] + sumd[i - 1];
  for (int i = 1; i <= 2 * n; i++) upd(1, 1, 2 * n, i);
  while (m--) {
    cin >> x >> y;
    l = y + 1;
    r = x - 1;
    if (l > r) r += n;
    ANS = get(1, 1, 2 * n, l, r);
    cout << (H[ANS.first] + H[ANS.second]) * 2 + dist(ANS.first, ANS.second)
         << endl;
  }
}
