#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] & (a[j] ^ ((1LL << 60LL) - 1))) {
        ++deg[i];
      }
      if (a[j] & (a[i] ^ ((1LL << 60LL) - 1))) {
        ++deg[j];
      }
    }
  }
  vector<int> mark(n);
  int cnt = n;
  while (cnt) {
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (mark[i]) continue;
      if (u == -1 || deg[i] > deg[u]) u = i;
    }
    if (deg[u] < cnt - 1) break;
    mark[u] = 1;
    --cnt;
    for (int v = 0; v < n; v++) {
      if (mark[v]) continue;
      if ((a[v] & (a[u] ^ ((1LL << 60LL) - 1))) == 0) continue;
      --deg[v];
    }
  }
  if (n <= 1) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (!mark[i]) ans += b[i];
  cout << ans << endl;
  return 0;
}
