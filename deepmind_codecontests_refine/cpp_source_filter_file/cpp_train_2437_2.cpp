#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m, p, t, w;
  int a[100001];
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  a[0] ^= a[n - 1] ^= a[0] ^= a[n - 1];
  for (i = 0; i < n; i++) cout << a[i];
  cout << endl;
  return 0;
}
