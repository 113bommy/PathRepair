#include <bits/stdc++.h>
using namespace std;
long long n, x[100000], h[100000], a[100000], b[100000], c[100000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
  a[0] = 1;
  b[0] = 0;
  c[0] = (x[0] + h[0] < x[1] ? 1 : 0);
  for (int i = 1; i < n; i++) {
    if (x[i] - h[i] > x[i - 1] + h[i - 1])
      a[i] = max(a[i], max(a[i - 1], max(b[i - 1], c[i - 1])) + 1);
    else if (x[i] - h[i] > x[i - 1])
      a[i] = max(a[i], max(a[i - 1], b[i - 1]) + 1);
    else
      a[i] = max(a[i - 1], max(b[i - 1], c[i - 1]));
    b[i] = c[i] = max(a[i - 1], max(b[i - 1], c[i - 1]));
    if (i != n - 1 && x[i] + h[i] < x[i + 1]) c[i]++;
    if (i == n - 1) c[i]++;
  }
  cout << max(a[n - 1], max(b[n - 1], c[n - 1]));
  return 0;
}
