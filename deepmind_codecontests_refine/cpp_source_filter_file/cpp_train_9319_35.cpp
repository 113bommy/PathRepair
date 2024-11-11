#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, a[100001], b[100001];
  long long x = 0, y = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) cin >> b[i];
  for (long long i = 0; i < n - 1; i++) {
    x |= a[i];
    y |= b[i];
  }
  if (n == 1)
    cout << a[0] + b[0];
  else
    cout << x + y;
}
