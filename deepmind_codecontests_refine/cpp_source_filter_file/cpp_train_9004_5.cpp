#include <bits/stdc++.h>
const int maxn = 1e6 + 10;
int a[maxn], b[maxn], l[maxn], r[maxn], s[maxn];
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, maxn, po;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  maxn = a[0];
  po = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > maxn) {
      maxn = a[i];
      po = i;
    }
  }
  for (int i = 0; i < n; i++) b[i] = a[(po + i) % n];
  b[n] = b[0];
  s[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    r[i] = i + 1;
    while (r[i] < n && b[i] > b[r[i]]) r[i] = r[r[i]];
    while (r[i] < n && b[i] == b[r[i]]) {
      s[i] = s[r[i]] + 1;
      r[i] = r[r[i]];
    }
  }
  l[0] = 0;
  for (int i = 1; i < n; i++) {
    l[i] = i - 1;
    while (l[i] > 0 && b[i] >= b[l[i]]) l[i] = l[l[i]];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += s[i];
    if (b[i] < b[0]) {
      if (l[i] == 0 && r[i] == n)
        ans += 1;
      else
        ans += 2;
    }
  }
  cout << ans << endl;
  return 0;
}
