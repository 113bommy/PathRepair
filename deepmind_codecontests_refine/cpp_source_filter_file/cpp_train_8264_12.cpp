#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100;
int n, m, a[maxn], seg[4 * maxn];
void build(int v, int second, int e) {
  if (e - second == 1) {
    seg[v] = a[second];
    return;
  }
  int mid = (second + e) / 2;
  build(2 * v, second, mid);
  build(2 * v + 1, mid, e);
  int x = e - second;
  if ((int)log2(x) % 2 == 1)
    seg[v] = seg[2 * v] | seg[2 * v + 1];
  else
    seg[v] = seg[2 * v] ^ seg[2 * v + 1];
}
void add(int p, int b, int v, int second, int e) {
  if (e - second == 1) {
    seg[v] = b;
    return;
  }
  int mid = (second + e) / 2;
  if (p < mid)
    add(p, b, 2 * v, second, mid);
  else
    add(p, b, 2 * v + 1, mid, e);
  int x = e - second;
  if ((int)log2(x) % 2 == 1)
    seg[v] = seg[2 * v] | seg[2 * v + 1];
  else
    seg[v] = seg[2 * v] ^ seg[2 * v + 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  n = (1 << n);
  for (int i = 0; i < n; i++) cin >> a[i];
  build(1, 0, n);
  for (int i = 0; i < m; i++) {
    int p, b;
    cin >> p >> b;
    p--;
    add(p, b, 1, 0, n);
    cout << seg[1] << endl;
  }
  return 0;
}
