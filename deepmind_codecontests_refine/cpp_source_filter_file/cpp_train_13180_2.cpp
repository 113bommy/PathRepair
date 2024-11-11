#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, l[102], r[102], a[102], first[102], last[102], m;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  m = 0;
  memset(a, 0, sizeof(a));
  memset(first, 0, sizeof(first));
  memset(last, 0, sizeof(last));
  for (int i = 1; i <= n; ++i)
    if (a[i] == 0) {
      a[i] = ++m;
      int j = i;
      while (r[j]) {
        j = r[j];
        a[j] = m;
      }
      last[i] = j;
      j = i;
      while (l[j]) {
        j = l[j];
        a[j] = m;
      }
      first[i] = j;
    }
  for (int i = 2; i <= m; ++i) {
    l[first[i]] = last[i - 1];
    r[last[i - 1]] = first[i];
  }
  r[last[1]] = first[2];
  for (int i = 1; i <= n; ++i) cout << l[i] << ' ' << r[i] << '\n';
  return 0;
}
