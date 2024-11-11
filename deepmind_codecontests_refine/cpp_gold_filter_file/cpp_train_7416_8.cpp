#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100001];
  a[0] = 0;
  for (int i = 1; i <= 100000; i++) {
    a[i] = a[i - 1] + 3 * i - 1;
  }
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int cnt = 0;
    while (n > 1) {
      int i = upper_bound(a, a + 100000, n) - a;
      i--;
      n -= a[i];
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
