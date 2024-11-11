#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int n, a, b;
int tree[4000];
bool d = 0;
int ans = 0;
void build(int v, int l, int r, int u) {
  if (d) return;
  if (l == r) {
    tree[v] = l == a || l == b;
    return;
  }
  int m = (l + r) / 2;
  build(2 * v, l, m, u - 1);
  if (d) return;
  build(2 * v + 1, m + 1, r, u - 1);
  if (d) return;
  tree[v] = tree[2 * v] || tree[2 * v + 1];
  if (tree[2 * v] && tree[2 * v + 1]) {
    ans = u;
    d = 1;
    return;
  }
}
int main() {
  cin >> n >> a >> b;
  int q = 0;
  a--;
  b--;
  int zz = n;
  while (n > 1) {
    q++;
    n /= 2;
  }
  build(1, 0, zz - 1, q);
  if (ans == q)
    cout << "Final!";
  else
    cout << ans;
  return 0;
}
