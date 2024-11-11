#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c1, c2, c3, c4;
  cin >> c1 >> c2 >> c3 >> c4;
  int n, m;
  cin >> n >> m;
  int a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int sb = 0, st = 0;
  for (int i = 0; i < n; i++) sb += min(a[i] * c1, c2);
  sb = min(sb, c3);
  for (int i = 0; i < n; i++) st += min(b[i] * c1, c2);
  st = min(st, c3);
  cout << min(st + sb, c4);
}
