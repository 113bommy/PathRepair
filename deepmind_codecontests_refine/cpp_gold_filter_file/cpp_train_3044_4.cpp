#include <bits/stdc++.h>
using namespace std;
int test;
long long n;
long long a[300001];
long long b[300001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    long long s = 0;
    cin >> n;
    long long mn = 1e17;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
    }
    a[0] = a[n];
    b[0] = b[n];
    long long res = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] > b[i - 1]) {
        res += a[i] - b[i - 1];
        a[i] = b[i - 1];
      }
    }
    for (int i = 1; i <= n; i++) {
      mn = min(mn, a[i]);
    }
    cout << res + mn << '\n';
  }
  return 0;
}
