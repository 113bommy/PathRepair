#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, l;
  cin >> n >> m;
  cin >> k;
  int a[k];
  bool a1[k];
  memset(a1, false, sizeof(a1));
  for (int i = 0; i < k; i++) cin >> a[i], a1[a[i]] = true;
  cin >> l;
  int b[l];
  bool b1[l];
  memset(b1, false, sizeof(b1));
  for (int i = 0; i < l; i++) cin >> b[i], b1[b[i]] = true;
  for (int i = 0; i < 10000000; i++) {
    if (a1[i % n]) b1[i % m] = true;
    if (b1[i % m]) a1[i % n] = true;
  }
  for (int i = 0; i < n; i++)
    if (!a1[i]) {
      cout << "NO\n";
      return 0;
    }
  for (int i = 0; i < m; i++)
    if (!b1[i]) {
      cout << "NO\n";
      return 0;
    }
  cout << "YES\n";
  return 0;
}
