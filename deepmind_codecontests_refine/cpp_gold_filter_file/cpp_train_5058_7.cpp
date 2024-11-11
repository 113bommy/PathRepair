#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long temp, temp1;
long long a[200001], b[200001], c[200001], d[200001];
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> temp >> temp1;
    a[i] = temp1;
    c[i] = temp;
  }
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> temp >> temp1;
    b[i] = temp;
    d[i] = temp1;
  }
  sort(a, a + n);
  sort(c, c + n);
  sort(d, d + m);
  sort(b, b + m);
  if (a[0] >= b[m - 1] && d[0] >= c[n - 1]) {
    cout << 0;
    return 0;
  }
  cout << max(b[m - 1] - a[0], c[n - 1] - d[0]);
}
