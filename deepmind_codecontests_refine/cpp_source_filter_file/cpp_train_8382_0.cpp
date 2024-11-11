#include <bits/stdc++.h>
using namespace std;
const int N = 3 * 1e5 + 5;
int p[N], inv[N], a[N], b[N], last[N];
int main() {
  std::ios::sync_with_stdio(false);
  memset(last, -1, sizeof(last));
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    inv[p[i]] = i;
  }
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    if (inv[a[i]] < inv[b[i]]) {
      last[inv[b[i]]] = max(last[inv[b[i]]], inv[a[i]]);
    } else {
      last[inv[a[i]]] = max(last[inv[a[i]]], inv[b[i]]);
    }
  }
  long long res = 0;
  int i, j;
  i = j = 0;
  while (j < n) {
    res += (j - i) + 1;
    ++j;
    if (last[j] != -1) {
      i = last[j] + 1;
    }
  }
  cout << res << endl;
  return 0;
}
