#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long int ans = 0;
  for (int i = 1; i <= n;) {
    long long int l, r;
    ans++;
    l = i;
    while (a[l] == -1 && l <= n) l++;
    if (l == n + 1) break;
    r = l + 1;
    while (a[r] == -1 && r <= n) r++;
    if (r == n + 1) break;
    if ((a[r] - a[l]) % (r - l)) {
      i = r;
      continue;
    }
    long long int d = (a[r] - a[l]) / (r - l);
    bool b = 0;
    for (int j = l - 1; j >= i; j--) {
      if (a[l] - (l - j) * d < 0) b = 1;
      if (b) {
        break;
      }
    }
    if (b) {
      i = r;
      continue;
    }
    for (int j = l + 1; j <= r; j++) {
      if (a[l] + (j - l) * d < 0) b = 1;
      if (b) {
        break;
      }
    }
    if (b) {
      i = r;
      continue;
    }
    long long int j = r + 1;
    while (j <= n) {
      if (a[j] == -1) {
        if (a[r] + (j - r) * d < 0) {
          b = 1;
          break;
        }
      } else {
        if (a[r] + (j - r) * d != a[j]) {
          b = 1;
          break;
        }
      }
      j++;
    }
    if (b) {
      i = j;
      continue;
    }
    break;
  }
  cout << ans;
}
