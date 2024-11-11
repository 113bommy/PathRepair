#include <bits/stdc++.h>
using namespace std;
long long a[100001], b[100001], c[100001], d[100001];
int main() {
  int n, m, j, k, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    c[i] = d[i] = 0;
  }
  k = n / 2;
  i = 0;
  j = 0;
  m = 0;
  while (m <= n - 1) {
    if (a[i] < b[j]) {
      c[i] = 1;
      i++;
      m++;
    } else {
      d[j] = 1;
      j++;
      m++;
    }
  }
  for (int p = 0; p < n / 2; p++) c[p] = d[p] = 1;
  if (n % 2 == 1)
    if (a[(n + 1) / 2] < b[(n + 1) / 2])
      c[(n + 1) / 2] = 1;
    else
      d[(n + 1) / 2] = 1;
  for (i = 0; i < n; i++) cout << c[i];
  cout << "\n";
  for (j = 0; j < n; j++) cout << d[j];
}
