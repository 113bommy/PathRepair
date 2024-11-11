#include <bits/stdc++.h>
using namespace std;
int i, j, cnt = 0;
int pre[150050], r[150050], l[150050];
int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x, y, tx, ty;
  cin >> n;
  for (i = 1; i < n + 1; i++) {
    pre[i] = r[i] = l[i] = i;
  }
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    x = find(x), y = find(y);
    pre[x] = y;
    r[l[y]] = x;
    l[y] = l[x];
  }
  for (i = 0; i < n; i++) {
    cout << y << (n - i - 1 ? ' ' : '\n');
    y = r[y];
  }
  return ~~(0 ^ 0 ^ 0);
}
