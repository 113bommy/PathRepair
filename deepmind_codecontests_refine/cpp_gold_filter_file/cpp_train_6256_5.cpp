#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
const int INF = 1e9;
void Insert(int val, int poz, int st, int dr, int curNode) {
  if (st == dr) {
    tree[curNode] = val;
    return;
  }
  int mid = (st + dr) >> 1;
  int left = curNode << 1, right = left | 1;
  if (poz <= mid) {
    Insert(val, poz, st, mid, left);
  } else {
    Insert(val, poz, mid + 1, dr, right);
  }
  tree[curNode] = min(tree[left], tree[right]);
}
int Query(int st, int dr, int l, int r, int curNode) {
  if (l <= st and dr <= r) {
    return tree[curNode];
  }
  int mid = (st + dr) >> 1;
  int left = curNode << 1, right = left | 1;
  int ansL = INF, ansR = INF;
  if (l <= mid) {
    ansL = Query(st, mid, l, r, left);
  }
  if (mid + 1 <= r) {
    ansR = Query(mid + 1, dr, l, r, right);
  }
  return min(ansL, ansR);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  tree.resize(n << 2);
  fill(tree.begin(), tree.end(), INF);
  vector<int> v(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    if (not v[i]) {
      continue;
    }
    Insert(v[i], i, 1, n, 1);
  }
  vector<int> fst(q + 1), last(q + 1);
  for (int i = 1; i <= n; ++i) {
    if (not v[i]) {
      continue;
    }
    if (not fst[v[i]]) {
      fst[v[i]] = i;
      last[v[i]] = i;
      continue;
    }
    last[v[i]] = i;
  }
  for (int i = 1; i <= q; ++i) {
    if (fst[i]) {
      if (Query(1, n, fst[i], last[i], 1) < i) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  bool ok = false;
  for (int i = 1; i <= n; ++i) {
    if (v[i] == q) {
      ok = true;
      break;
    }
  }
  if (not ok) {
    for (int i = 1; i <= n; ++i) {
      if (v[i] == 0) {
        v[i] = q;
        ok = true;
        break;
      }
    }
    if (not ok) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = n; i >= 1; --i) {
    if (not v[i]) {
      v[i] = v[i + 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (not v[i]) {
      v[i] = v[i - 1];
    }
    cout << v[i] << ' ';
  }
  cout << '\n';
}
