#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000];
int main() {
  int m, n;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + m);
  sort(b, b + n);
  int q = a[0];
  int pos = n - 1;
  long long ans = 0;
  while (pos >= 0) {
    int s = max(0, pos - q + 1);
    for (int i = s; i <= pos; i++) {
      ans += b[i];
    }
    pos = s - 3;
  }
  cout << ans << "\n";
}
