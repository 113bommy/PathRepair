#include <bits/stdc++.h>
using namespace std;
long long n, i, a[1000000], x, x1, b[1000000], c[1000000], k, p;
int main() {
  cin >> n >> p >> k;
  if ((p - k) > 0)
    cout << "<<"
         << " ";
  for (i = 0; i <= k - 1; i++) {
    if ((p - k + i) > 0) cout << p - k + i << " ";
  }
  cout << "(" << p << ")"
       << " ";
  for (i = p + 1; i <= min((p + k), n); i++) cout << i << " ";
  if (i != n) cout << ">>";
}
