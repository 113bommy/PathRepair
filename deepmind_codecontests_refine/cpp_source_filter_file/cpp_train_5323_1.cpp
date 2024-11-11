#include <bits/stdc++.h>
const long long MXN = 1e6 + 1;
using namespace std;
int n, f, s;
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= MXN; i++) {
    if (i * 7 <= n && (n - i * 7) % 4 == 0) {
      f = i;
      s = (n - i * 7) / 4;
      break;
    }
  }
  if (f == 0 && s == 0) return cout << -1, 0;
  for (int i = 1; i <= s; i++) {
    cout << 4;
  }
  for (int i = 1; i <= f; i++) {
    cout << 7;
  }
  return 0;
}
