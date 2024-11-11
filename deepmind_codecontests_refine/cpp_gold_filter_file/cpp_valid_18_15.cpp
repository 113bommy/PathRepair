#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int nxt[N];
void solve() {
  int n, m;
  cin >> n >> m;
  memset(nxt, -1, sizeof(nxt));
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    nxt[x - 1] = y - 1;
    nxt[y - 1] = x - 1;
  }
  for (int i = 0; i < 2 * n; i++) {
    if (nxt[i] == -1) {
      int p = (i + 1) % (2 * n);
      int q = n - m;
      while (1) {
        if (nxt[p] == -1) q--;
        if (q == 0) break;
        p = (p + 1) % (2 * n);
      }
      nxt[p] = i;
      nxt[i] = p;
      m++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (nxt[i] < i) continue;
    for (int j = 0; j < 2 * n; j++) {
      if (nxt[j] < j) continue;
      if ((i < j && j < nxt[i] && nxt[i] < nxt[j]) ||
          (j < i && i < nxt[j] && nxt[j] < nxt[i]))
        cnt++;
    }
  }
  cout << cnt / 2 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
