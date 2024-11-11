#include <bits/stdc++.h>
using namespace std;
long long int fun(long long int x[], long long int l, long long int r) {
  long long int i, sum = 0;
  for (i = l; i <= r; i++) sum |= x[i];
  return sum;
}
int main() {
  int n;
  cin >> n;
  long long int i, j, a[1005], b[1005];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  long long int res = INT_MIN;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      long long int sum = fun(a, i, j) + fun(b, i, j);
      res = max(res, sum);
    }
  }
  cout << res << endl;
}
