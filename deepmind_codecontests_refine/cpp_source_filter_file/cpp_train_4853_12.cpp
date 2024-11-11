#include <bits/stdc++.h>
using namespace std;
long long n, a[5001], d1, d2, d3, c, d, cum[5001], nxt[5001], mn;
long long sum(int i, int j) {
  if (i == 0) {
    if (j == 0) {
      return 0;
    }
    return cum[j - 1];
  }
  return cum[j - 1] - cum[i - 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  d = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cum[i] = a[i];
    if (i) {
      cum[i] += cum[i - 1];
    }
  }
  for (int i = n; i >= 0; i--) {
    c += a[i];
    if (c < mn) {
      d = i;
      mn = c;
    }
    nxt[i] = d;
  }
  int mx = -1e18;
  for (int i = 0; i <= n; i++) {
    c = 0;
    for (int j = i; j <= n; j++) {
      c = sum(0, i) - sum(i, j) + sum(j, nxt[j]) - sum(nxt[j], n);
      if (c > mx) {
        mx = c;
        d1 = i;
        d2 = j;
        d3 = nxt[j];
      }
    }
  }
  cout << d1 << " " << d2 << " " << d3;
  return 0;
}
