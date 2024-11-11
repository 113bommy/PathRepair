#include <bits/stdc++.h>
using namespace std;
int n, z, ans, v[200100];
bool m[200100];
int main() {
  cin >> n >> z;
  for (int i = 1, x; i <= n; i++) cin >> v[i];
  sort(v + 1, v + 1 + n);
  for (int i = 1, j = n / 2; i <= n; i++) {
    if (m[i]) continue;
    while (j <= n && (v[j] - v[i] < z || m[j])) j++;
    if (j <= n) ans++, m[i] = m[j] = 1;
  }
  cout << ans << endl;
}
