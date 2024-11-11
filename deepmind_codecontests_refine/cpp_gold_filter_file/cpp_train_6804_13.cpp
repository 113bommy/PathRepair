#include <bits/stdc++.h>
using namespace std;
int c = 1;
long long ans;
int n;
long long k;
long long a[100001], b[100001];
int l, r;
long long toadd;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(&a[1], &a[n + 1]);
  l = r = 1;
  ans = a[1];
  for (int i = 1; i <= n; i++) b[i] = a[i];
  while (r <= n) {
    toadd = (r - l) * (b[r] - b[r - 1]);
    while (toadd > k && l != r) {
      k += b[r - 1] - b[l];
      a[l] = b[l];
      l++;
      toadd = (r - l) * (b[r] - b[r - 1]);
    }
    k -= toadd;
    if (r - l + 1 > c) {
      c = r - l + 1;
      ans = b[r];
    }
    r++;
  }
  cout << c << " " << ans;
  return 0;
}
