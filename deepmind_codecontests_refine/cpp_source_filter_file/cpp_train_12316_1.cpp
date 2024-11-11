#include <bits/stdc++.h>
long long int arr[10000000 + 99], lo[101], jx[101], jy[101];
using namespace std;
int main() {
  long long int k, l, m, n, d, ans = 0;
  cin >> k >> l >> m >> n >> d;
  for (int i = 0; i < d; i++) {
    if (i % k == 0 && arr[i] == 0 && k < d) {
      ans++;
      arr[i] = 1;
    }
    if (i % l == 0 && arr[i] == 0 && l < d) {
      ans++;
      arr[i] = 1;
    }
    if (i % m == 0 && arr[i] == 0 && m < d) {
      arr[i] = 1;
      ans++;
    }
    if (i % n == 0 && arr[i] == 0 && n < d) {
      arr[i] = 1;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
