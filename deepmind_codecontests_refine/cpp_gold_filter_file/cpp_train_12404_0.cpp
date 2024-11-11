#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  int n, m, b, mina, maxc;
  cin >> n >> m >> b;
  int a[n], c[m];
  for (i = 0; i < n; i++) cin >> a[i];
  mina = *min_element(a, a + n);
  for (i = 0; i < m; i++) cin >> c[i];
  maxc = *max_element(c, c + m);
  if ((b / mina) * maxc + (b % mina) > b)
    cout << (b / mina) * maxc + (b % mina);
  else
    cout << b;
  return 0;
}
