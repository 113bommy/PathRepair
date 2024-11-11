#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
const int BUFSIZE = (1 << 12) + 17;
char BUF[BUFSIZE + 1], *inp = BUF;
const int MN = 200111;
int n, p[MN], bit[MN];
void update(int u) {
  for (int x = u; x <= n + n; x += ((x) & (-(x)))) bit[x]++;
}
int get(int u) {
  int res = 0;
  for (int x = u; x > 0; x -= ((x) & (-(x)))) res += bit[x];
  return res;
}
int main() {
  ios ::sync_with_stdio(false);
  while (cin >> n) {
    for (int i = (1), _b = (n); i <= _b; i++) {
      int u, v;
      cin >> u >> v;
      p[u] = v;
      p[v] = u;
    }
    long long res = n * (n - 1LL) * (n - 2) / 3;
    memset(bit, 0, sizeof bit);
    for (int i = (1), _b = (n + n); i <= _b; i++) {
      if (p[i] > i) continue;
      int x = get(i) - get(p[i]);
      int z = (i - p[i] - 1) - 2 * x;
      long long y = n - 1 - x - z;
      res -= x * y * 2 + z * (x + y);
      update(p[i]);
    }
    cout << res / 2 << endl;
  }
  return 0;
}
