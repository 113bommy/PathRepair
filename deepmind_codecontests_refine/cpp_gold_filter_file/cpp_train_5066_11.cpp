#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005] = {0};
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  while (m--) {
    long long x;
    cin >> x;
    int pos = lower_bound(a + 1, a + 1 + n, x) - a;
    cout << pos << " " << x - a[pos - 1] << endl;
  }
  return 0;
}
