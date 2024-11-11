#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], b[110];
int gcd(int a, int b) { return a % b ? gcd(b, a % b) : b; }
int main() {
  int i, j;
  cin >> n >> m;
  for (i = n; i >= 0; i--) cin >> a[i];
  for (j = m; j >= 0; j--) cin >> b[j];
  for (i = n; i >= 0; i--)
    if (a[i]) break;
  for (j = m; j >= 0; j--)
    if (b[j]) break;
  if (i > j) {
    if (a[i] * b[j] > 0)
      puts("Infinity");
    else
      puts("-Infinity");
  } else if (i < j) {
    puts("0/1");
  } else {
    int d = gcd(a[i], b[j]);
    a[i] /= d, b[j] /= d;
    if (b[j] < 0) a[i] *= -1, b[j] *= -1;
    printf("%d/%d\n", a[i], b[j]);
  }
  return 0;
}
