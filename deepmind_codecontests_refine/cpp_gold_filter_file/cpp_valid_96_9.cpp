#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
struct Node {
  long long tot;
  long long pref, suff;
  Node() { tot = pref = suff = 0; }
} st[800100];
int arr[200100];
void U(int node, int l, int r, int ind, int val) {
  if (l > ind || r < ind) return;
  if (l == r) {
    st[node].tot = 1;
    st[node].pref = 1;
    st[node].suff = 1;
    return;
  }
  int mid = (l + r) / 2;
  U(node * 2, l, mid, ind, val);
  U(node * 2 + 1, mid + 1, r, ind, val);
  st[node].tot = st[node * 2].tot + st[node * 2 + 1].tot;
  if (arr[mid + 1] >= arr[mid]) {
    st[node].tot += st[node * 2].suff * st[node * 2 + 1].pref;
    if (st[node * 2 + 1].pref == (r - mid))
      st[node].suff = st[node * 2].suff + st[node * 2 + 1].pref;
    else
      st[node].suff = st[node * 2 + 1].suff;
    if (st[node * 2].suff == (mid - l + 1))
      st[node].pref = st[node * 2].suff + st[node * 2 + 1].pref;
    else
      st[node].pref = st[node * 2].pref;
  } else {
    st[node].pref = st[node * 2].pref;
    st[node].suff = st[node * 2 + 1].suff;
  }
}
pair<Node, pair<int, int> > S(int node, int l, int r, int tl, int tr) {
  if (l > tr || r < tl) return {Node(), {-1, -1}};
  if (l >= tl && r <= tr) {
    return {st[node], {l, r}};
  }
  int mid = (l + r) / 2;
  pair<Node, pair<int, int> > lson = S(node * 2, l, mid, tl, tr);
  pair<Node, pair<int, int> > rson = S(node * 2 + 1, mid + 1, r, tl, tr);
  if (lson.second.first == -1)
    return rson;
  else if (rson.second.first == -1)
    return lson;
  Node ret;
  ret.tot = lson.first.tot + rson.first.tot;
  if (arr[mid + 1] >= arr[mid]) {
    ret.tot += lson.first.suff * rson.first.pref;
    if (rson.first.pref == (rson.second.second - mid))
      ret.suff = lson.first.suff + rson.first.pref;
    else
      ret.suff = rson.first.suff;
    if (lson.first.suff == (mid - lson.second.first + 1)) {
      ret.pref = lson.first.suff + rson.first.pref;
    } else {
      ret.pref = lson.first.pref;
    }
  } else {
    ret.pref = lson.first.pref;
    ret.suff = rson.first.suff;
  }
  return {ret, {lson.second.first, rson.second.second}};
}
void output(int node, int l, int r) {
  cout << l << " " << r << " " << st[node].pref << " " << st[node].suff << "\n";
  if (l == r) return;
  int mid = (l + r) / 2;
  output(node * 2, l, mid);
  output(node * 2 + 1, mid + 1, r);
}
int main() {
  fastIO();
  int N, Q;
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    U(1, 1, N, i, arr[i]);
  }
  for (int i = 1; i <= Q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      arr[b] = c;
      U(1, 1, N, b, c);
    } else {
      cout << S(1, 1, N, b, c).first.tot << "\n";
    }
  }
}
