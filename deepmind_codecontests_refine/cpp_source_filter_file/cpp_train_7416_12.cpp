#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 10;
const int N = 1e4 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int t, n, m;
long long a[N];
int main() {
  cin >> t;
  a[0] = 2;
  for (int i = 1; i < N; i++) {
    a[i] = a[i - 1] + 3 * i + 2;
  }
  while (t--) {
    cin >> n;
    int ans = 0;
    while (n >= 2) {
      int l = 0, r = N, mid;
      while (l < r) {
        mid = l + r + 1 >> 1;
        if (a[mid] > n)
          r = mid - 1;
        else
          l = mid;
      }
      ans += n / a[r];
      n = n % a[r];
    }
    printf("%d\n", ans);
  }
  return 0;
}
