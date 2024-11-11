#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0, mx = -0x3f3f3f3f3f3f3f3f;
    int l = 1, r = n, tmp = 1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
      if (sum > mx) {
        mx = sum;
        r = i;
        l = tmp;
      }
      if (sum <= 0) {
        sum = 0;
        tmp = i + 1;
      }
    }
    if (l == 1 && r == n && a[l] > 0 && a[r] > 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
