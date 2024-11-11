#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, c = 0, d = 0, A;
  cin >> n;
  long long int a[n + 1], i;
  a[0] = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  for (i = 1; i <= n / 2; i++) c = c + a[i];
  for (i = n / 2 + 1; i <= n; i++) d = d + a[i];
  A = c * c + d * d;
  cout << A << endl;
  return 0;
}
