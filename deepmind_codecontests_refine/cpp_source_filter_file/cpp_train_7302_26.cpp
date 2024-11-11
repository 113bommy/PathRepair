#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
long long a[maxn], b[maxn];
int main() {
  ios::sync_with_stdio(false);
  long long ans = 0, tol = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    tol += a[i];
  }
  if (tol < 0)
    for (int i = 0; i < n; ++i) a[i] = -a[i];
  for (int i = 0; i < 62; ++i) {
    tol = 0;
    for (int j = 0; j < n; ++j) {
      if (b[j] >> i & 1) {
        tol += a[j];
      }
    }
    if (tol > 0) {
      ans |= 1LL << i;
      for (int j = 0; j < n; ++j) {
        if (b[j] >> i & 1) {
          a[j] = -a[j];
        }
      }
    }
  }
  cout << ans << endl;
}
