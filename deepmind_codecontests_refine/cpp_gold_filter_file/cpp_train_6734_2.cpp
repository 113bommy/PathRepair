#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, l;
  cin >> n >> k >> l;
  long long int a[(n * k)];
  for (int i = 0; i < (n * k); i++) cin >> a[i];
  sort(a, a + (n * k));
  long long int lw = upper_bound(a, a + (n * k), (a[0] + l)) - a;
  long long n1 = n;
  long long int up = (n * k) - lw;
  long long int ct = 0;
  long long int h1 = -100;
  if (k != 1)
    h1 = up / (k - 1);
  else {
    if ((a[0] + l) < a[(n * k) - 1])
      h1 = -100;
    else
      h1 = n;
  }
  for (int i = (lw - 1); i >= 0; i--) {
    if (n <= 0 || h1 <= 0) break;
    ct += a[i];
    n--;
    h1--;
  }
  int lk = 0;
  while (n > 0 && lw >= n1) {
    ct += a[lk];
    lk += k;
    n--;
  }
  if (n1 == 1)
    cout << a[0] << endl;
  else if (lw < n1 || h1 == -100)
    cout << 0 << endl;
  else
    cout << ct << endl;
  return 0;
}
