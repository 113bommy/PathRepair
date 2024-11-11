#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k, neg = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] < 0 ? ++neg : neg;
  }
  if (neg >= k) {
    for (int i = 0; i < k; i++) {
      a[i] *= -1;
    }
  } else {
    for (int i = 0; i < neg; i++) {
      a[i] *= -1;
      k--;
    }
    sort(a, a + n);
    if (k & 1) {
      a[0] *= -1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans += a[i];
  cout << ans;
  return 0;
}
