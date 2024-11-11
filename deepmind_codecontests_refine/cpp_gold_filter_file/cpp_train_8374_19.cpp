#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
const int mod = 1000000000 + 7;
int fa[maxn << 1];
int cnt;
int find(int x) {
  if (fa[x] == x) {
    return x;
  } else {
    return fa[x] = find(fa[x]);
  }
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    cnt--;
    fa[b] = a;
  }
}
int abs(int x) { return x < 0 ? -x : x; }
int MAIN() {
  int n, k;
  cin >> n >> k;
  cnt = 2 * n + 4;
  for (int i = 0; i < cnt; i++) {
    fa[i] = i;
  }
  int a, b;
  char op[2];
  while (k--) {
    cin >> a >> b >> op;
    a--, b--;
    int l, r;
    l = abs(a - b);
    r = min(a + b, 2 * n - 2 - a - b);
    if (op[0] == 'o') {
      merge(2 * l, 2 * (r + 2) + 1);
      merge(2 * l + 1, 2 * (r + 2));
    } else {
      merge(2 * l, 2 * (r + 2));
      merge(2 * l + 1, 2 * (r + 2) + 1);
    }
  }
  for (int i = 0; i < n + 2; i++) {
    if (find(2 * i) == find(2 * i + 1)) {
      cout << "0" << endl;
      return 0;
    }
  }
  cnt = (cnt - 4) / 2;
  int ans = 1;
  for (int i = 0; i < cnt; i++) {
    ans = (ans + ans) % mod;
  }
  cout << ans << endl;
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  return MAIN();
}
