#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c;
  cin >> n >> m >> c;
  int a[n], b[m];
  int p[n + 1];
  for (int i = 0; i <= n; i++) p[i] = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    p[i] += b[i];
    p[n - m + i + 1] -= b[i];
  }
  for (int i = 1; i < n; i++) p[i] += p[i - 1];
  for (int i = 0; i < n; i++) cout << (a[i] + p[i]) % c << " ";
  return 0;
}
