#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long mn = a[0];
  cout << mn << endl;
  long long ct = 1;
  for (long long i = 0; i < n; i++) {
    if (ct == k) break;
    if (a[i] - mn) {
      cout << a[i] - mn << endl;
      mn += a[i] - mn;
      ct++;
    }
  }
  if (ct < k) {
    for (long long i = ct; i < k; i++) cout << 0 << endl;
  }
  cout << "\n";
  return 0;
}
