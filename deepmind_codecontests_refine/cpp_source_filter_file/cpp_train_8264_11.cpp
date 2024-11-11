#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int len, tree[MAXN * 4];
void Build(int v, int r) {
  if (r != 1) {
    Build(2 * v, r - 1), Build(2 * v + 1, r - 1);
  }
  if (r % 2 == 1) {
    tree[v] = (tree[2 * v] | tree[2 * v + 1]);
  } else
    tree[v] = (tree[2 * v] ^ tree[2 * v + 1]);
}
void Up(int v, int r) {
  if (r % 2 == 1) {
    tree[v] = (tree[2 * v] | tree[2 * v + 1]);
  } else
    tree[v] = (tree[2 * v] ^ tree[2 * v + 1]);
  if (v != 1) Up(v / 2, r + 1);
}
int main() {
  int n, m;
  cin >> n >> m;
  len = 1 << n;
  for (int i = 0; i < len; i++) {
    cin >> tree[i + len];
  }
  Build(1, n);
  for (int i = 0; i < m; i++) {
    int p, b;
    cin >> p >> b;
    tree[len + p - 1] = b;
    Up((len + p) / 2, 1);
    cout << tree[1] << '\n';
  }
  return 0;
}
