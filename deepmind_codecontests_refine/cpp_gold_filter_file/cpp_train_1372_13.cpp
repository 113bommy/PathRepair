#include <bits/stdc++.h>
using namespace std;
long long a[200007], d[200007], t[200007];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long type;
    cin >> type;
    if (type == 1) {
      long long x, y;
      cin >> x >> y;
      a[x - 1] = y;
      t[x - 1] = i;
    } else {
      long long x;
      cin >> x;
      d[i] = x;
    }
  }
  for (long long i = q - 1; i > 0; i--) {
    d[i - 1] = max(d[i - 1], d[i]);
  }
  for (long long i = 0; i < n; i++) {
    cout << max(a[i], d[t[i]]) << " ";
  }
  return 0;
}
