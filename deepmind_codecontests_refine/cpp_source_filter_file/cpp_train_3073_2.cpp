#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, sz;
int a[30], b[30], c[101000];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1) cnt++;
  }
  if (cnt > 1) {
    cout << 0 << endl;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= a[i]; j++) printf("%c", 'a' + i - 1);
    return 0;
  }
  int g = a[1];
  for (int i = 2; i <= n; i++) g = gcd(g, a[i]);
  cnt = 0;
  for (int i = 1; i <= n; i++) b[i] = a[i] / g, cnt += a[i] & 1;
  cout << g << endl;
  if (cnt > 1) {
    g /= 2;
    for (int i = 1; i <= n; i++) b[i] *= 2;
  }
  m = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= b[i]; j++) m++;
  int l = 1, r = m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= b[i] / 2; j++) c[l++] = i, c[r--] = i;
  for (int i = 1; i <= n; i++)
    if (b[i] & 1) c[l++] = i;
  while (g--) {
    for (int i = 1; i <= m; i++) printf("%c", c[i] + 'a' - 1);
  }
  return 0;
}
