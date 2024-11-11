#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int n, a[N];
int rr[N], cnt;
int f[N][N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] != a[i - 1]) rr[++cnt] = a[i];
  }
  for (int len = 2; len <= cnt; ++len) {
    for (int l = 1, r = len; r <= cnt; ++l, ++r) {
      if (a[l] == a[r])
        f[l][r] = f[l + 1][r - 1] + 1;
      else
        f[l][r] = min(f[l + 1][r], f[l][r - 1]) + 1;
    }
  }
  cout << f[1][cnt];
  return 0;
}
