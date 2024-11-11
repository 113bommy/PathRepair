#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 123, inf = 2e9, mod = 1e9 + 7;
long long n, cnt[5], cur, a[100], b[5];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < 5; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    cur += a[i];
    for (int j = 4; j >= 0; j--) cnt[j] += b[j] / cur, cur %= b[j];
  }
  for (int j = 0; j < 5; j++) cout << cnt[j] << " ";
  cout << endl << cur;
}
