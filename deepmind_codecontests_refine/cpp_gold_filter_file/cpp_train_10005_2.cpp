#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1LL << 60;
map<int, int> Id;
int Count = 1;
int P[1 << 20];
int D[1 << 20];
int GetId(int key) {
  if (Id.count(key)) {
    return Id[key];
  }
  P[Count] = Count;
  Id[key] = Count;
  return Count++;
}
int GetRoot(int u) {
  if (P[u] == u) {
    return u;
  } else {
    int v = P[u];
    int root = GetRoot(P[u]);
    D[u] = D[v] ^ D[u];
    P[u] = root;
    return root;
  }
}
int query(int l, int r, int x, int t) {
  int lId = GetId(l);
  int rId = GetId(r);
  int lRoot = GetRoot(lId);
  int rRoot = GetRoot(rId);
  if (t == 1) {
    if (lRoot == rRoot) {
      return -1;
    } else {
      P[lRoot] = rRoot;
      D[lRoot] = D[lId] ^ x ^ D[rId];
      return -1;
    }
  } else {
    if (lRoot == rRoot) {
      return D[lId] ^ D[rId];
    } else {
      return -1;
    }
  }
}
int main() {
  int q;
  scanf("%d", &q);
  int last = 0;
  int t, l, r, x;
  while (q--) {
    if (last == -1) {
      last = 1;
    }
    scanf("%d %d %d", &t, &l, &r);
    l ^= last;
    r ^= last;
    if (l > r) {
      swap(l, r);
    }
    ++r;
    if (t == 1) {
      scanf("%d", &x);
      x ^= last;
      query(l, r, x, t);
    } else {
      last = query(l, r, x, t);
      printf("%d\n", last);
    }
  }
  return 0;
}
