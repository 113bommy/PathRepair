#include <bits/stdc++.h>
using namespace std;
long long int n, m, t, i = 1, j, k, c = 0, x, y, z, d = 0, g, h, b, e, f, l, a1,
                       a2, a3, b1, b2, b3;
vector<long long int> v, w;
int main() {
  cin >> n;
  long long int a[n + 1];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (n > 1)
    cout << a[n / 2];
  else
    cout << a[0];
}
