#include <bits/stdc++.h>
using namespace std;
long long i, j, n, a[1005], b[1005], cnt, md = 1000000007;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = 2;
  }
  for (i = 1; i <= n; i++) {
    if (a[i] != i) {
      for (j = a[i]; j < i; j++) {
        b[i] = (b[j] + b[i]) % md;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    cnt = (cnt + b[i]) % md;
  }
  cout << cnt;
  return 0;
}
