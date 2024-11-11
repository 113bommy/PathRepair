#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long long N = 1e6 + 5;
const long long mod = 998244353;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
long long test = 1, n, m, val[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                                     9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
string second;
struct NODE {
  long long a, b, c, d, sz;
};
NODE tree[4 * N + 8];
NODE merge(NODE A, NODE B, int i) {
  NODE C;
  C.a = (A.a * B.a) % mod;
  C.b = (A.a * B.b) % mod;
  C.c = (A.c * B.a) % mod;
  C.d = (A.c * B.b) % mod;
  C.sz = A.sz + B.sz;
  int t = (second[i] - '0') * 10 + second[i + 1] - '0';
  if (t > 9 and t < 20) {
    C.a = (C.a + A.b * B.c % mod * val[t]) % mod;
    if (C.sz > 2) C.b = (C.b + A.b * B.d % mod * val[t]) % mod;
    if (C.sz > 2) C.c = (C.c + A.d * B.c % mod * val[t]) % mod;
    if (C.sz > 3) C.d = (C.d + A.d * B.d % mod * val[t]) % mod;
  }
  return C;
}
void build(int node, int start, int end) {
  if (start == end) {
    int o = second[start] - '0';
    tree[node] = {val[o], 1, 1, 1, 1};
  } else {
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid);
  }
}
void update(int node, int start, int end, int idx, int v) {
  if (start == end) {
    second[start] = v + '0';
    int o = second[start] - '0';
    tree[node] = {val[o], 1, 1, 1, 1};
  } else {
    int mid = (start + end) / 2;
    if (start <= idx and idx <= mid)
      update(2 * node, start, mid, idx, v);
    else
      update(2 * node + 1, mid + 1, end, idx, v);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid);
  }
}
void solve() {
  cin >> n >> m >> second;
  second = '#' + second;
  build(1, 1, n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    update(1, 1, n, u, v);
    cout << tree[1].a << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
