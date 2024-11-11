#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-8);
const int MAX_N = 150005;
int l[MAX_N], r[MAX_N], nxt[MAX_N], rnk[MAX_N];
int findRight(int x) {
  if (r[x] == x) return x;
  return r[x] = findRight(r[x]);
}
int findLeft(int y) {
  if (l[y] == y) return y;
  return l[y] = findLeft(l[y]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  memset(nxt, -1, sizeof(nxt));
  for (int i = 0; i < n; ++i) {
    l[i] = i;
    r[i] = i;
    rnk[i] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    int lx = findLeft(x), ly = findLeft(y), rx = findRight(x),
        ry = findRight(y);
    if (rx - lx < ry - ly) {
      swap(rx, ry);
      swap(lx, ly);
      swap(x, y);
    }
    nxt[rx] = ly;
    r[rx] = ry;
    l[ly] = lx;
  }
  int st = findLeft(0);
  while (st != -1) {
    cout << st + 1 << ' ';
    st = nxt[st];
  }
  return 0;
}
