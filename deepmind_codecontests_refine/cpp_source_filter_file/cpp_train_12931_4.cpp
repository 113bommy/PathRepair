#include <bits/stdc++.h>
using namespace std;
string a[25], b[25];
int c[2025];
int m, n, q, num;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < q; i++) {
    num = c[i];
    cout << a[((num - 1) % n + 1)] << b[((num - 1) % m + 1)];
  }
  return 0;
}
