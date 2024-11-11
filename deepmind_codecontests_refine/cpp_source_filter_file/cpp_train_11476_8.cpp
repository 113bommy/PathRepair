#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 % m;
    return 0;
  }
  long long mas[n];
  for (int i = 0; i < n; i++) cin >> mas[i];
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      (cnt *= abs(mas[i] - mas[j])) %= m;
    }
  }
  cout << cnt;
  return 0;
}
