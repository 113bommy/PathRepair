#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, a[200], k, mx = 0, c = 0, c2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c += a[i];
    mx = max(mx, a[i]);
  }
  for (int i = 0; i < n; i++) {
    c2 += mx - a[i];
  }
  k = 0;
  while (c2 + k * n <= c) {
    k++;
  }
  cout << k + mx;
  return 0;
}
