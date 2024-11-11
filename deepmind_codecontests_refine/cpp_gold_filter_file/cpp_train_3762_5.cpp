#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, a[300000], cnt = 0, t;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n / 2; i++) {
    t = (a[i] + a[n - i - 1]);
    cnt += (t * t);
  }
  cout << cnt;
  return 0;
}
