#include <bits/stdc++.h>
const int N = 1e6;
const double PI = 3.14;
using namespace std;
long long n, m, k, b[N], a[N], sum;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < m; i++) {
    long long x;
    cin >> x;
    x--;
    b[i] = a[x];
    sum -= a[x];
  }
  sort(b, b + m);
  for (int i = m - 1; i >= 0; i--) {
    if (b[i] > sum)
      sum += b[i];
    else
      sum *= 2;
  }
  cout << sum;
  return 0;
}
