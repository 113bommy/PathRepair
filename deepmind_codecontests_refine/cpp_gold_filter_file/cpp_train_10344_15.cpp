#include <bits/stdc++.h>
using namespace std;
int a[200000], b[200000], c[200000], d[200000];
int main() {
  long long n, m, i, s1, s2, x, j;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    c[a[i]] = i;
    d[a[i]] = (n + 1) - i;
  }
  s1 = 0;
  s2 = 0;
  cin >> m;
  for (j = 1; j <= m; j++) {
    cin >> b[j];
    s1 += c[b[j]];
    s2 += d[b[j]];
  }
  cout << s1 << " " << s2;
  return 0;
}
