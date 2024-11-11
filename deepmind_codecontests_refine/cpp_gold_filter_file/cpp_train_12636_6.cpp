#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 10;
int n;
int a[MAXN];
int m[MAXN * 2];
int main() {
  cin >> n;
  memset(m, -1, sizeof(m));
  for (int i = 0; i < n; ++i) {
    a[i] = i;
    m[i] = i;
  }
  for (int k = 2; k <= n; ++k) {
    for (int j = (n - 1) / k * k; j >= 0; j -= k) {
      int x = k - 2 + j;
      int y = m[x];
      m[x] = -1;
      a[y] += min(k - 1, n - j - 1) + 1;
      m[a[y]] = y;
    }
  }
  for (int i = n - 1; i < 2 * n - 1; ++i) cout << m[i] + 1 << " ";
  cout << endl;
  return 0;
}
