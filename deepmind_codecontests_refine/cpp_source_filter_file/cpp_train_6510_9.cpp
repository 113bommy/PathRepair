#include <bits/stdc++.h>
using namespace std;
int a[int(1e5 + 5) * 2], b[int(1e5 + 5) * 2], c[int(1e5 + 5) * 2], i, m, ans, k,
    l, j, q, x, n, ma, ma1, ind;
string s;
map<int, int> f;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i], f[a[i]]++;
  cin >> m;
  for (i = 0; i < m; i++) cin >> b[i];
  for (i = 0; i < m; i++) cin >> c[i];
  for (i = 0; i < m; i++) {
    if (f[b[i]] > ma || (f[b[i]] == ma && f[c[i]] > ma1)) {
      ma = f[b[i]];
      ma1 = f[c[i]];
      ind = i + 1;
    }
  }
  cout << ind;
}
