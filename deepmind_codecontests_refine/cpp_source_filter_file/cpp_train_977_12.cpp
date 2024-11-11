#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
const int BUFSIZE = (1 << 12) + 17;
char BUF[BUFSIZE + 1], *inp = BUF;
const int MN = 100111;
int n, a[MN], f[MN], bit[MN];
int get(int u) {
  int res = 0;
  for (int x = u; x > 0; x -= ((x) & (-(x)))) res = max(res, bit[x]);
  return res;
}
void update(int u, int k) {
  for (int x = u; x <= n; x += ((x) & (-(x)))) bit[u] = max(bit[u], k);
}
int main() {
  ios ::sync_with_stdio(false);
  while (cin >> n) {
    for (int i = (1), _b = (n); i <= _b; i++) cin >> a[i];
    memset(bit, 0, sizeof bit);
    int res = 0;
    for (int i = (1), _b = (n); i <= _b; i++) {
      f[i] = get(a[i]) + 1;
      update(a[i], f[i]);
      res = max(res, f[i]);
    }
    cout << res << endl;
  }
  return 0;
}
