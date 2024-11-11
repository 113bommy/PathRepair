#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const int N = 1e7;
const int K = 1;
int n, k;
int nxt[2][N];
int sz[N];
int cntV = 1;
ll ans;
int getb(int x, int i) { return (x >> i) & 1; }
void add(int x) {
  int v = 0;
  for (int i = K; i >= 0; --i) {
    int b = getb(x, i);
    if (nxt[b][v] == 0) {
      nxt[b][v] = cntV++;
    }
    v = nxt[b][v], ++sz[v];
  }
}
void go(int x) {
  int v = 0;
  for (int i = K; i >= 0; --i) {
    int bx = getb(x, i), kx = getb(k, i);
    if (kx == 0) {
      ans += sz[nxt[bx ^ 1][v]];
      v = nxt[bx][v];
    } else {
      v = nxt[bx ^ 1][v];
    }
    if (v == 0) {
      return;
    }
  }
  ans += sz[v];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  add(0);
  for (int i = 0, x = 0, a; i < n; ++i) {
    cin >> a;
    x ^= a;
    go(x), add(x);
  }
  cout << ans << '\n';
  return 0;
}
