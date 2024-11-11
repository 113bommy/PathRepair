#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc-- > 0) {
    int n;
    cin >> n;
    vector<int> a(n), c(32);
    vector<bitset<32>> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      b[i] = a[i];
      for (int j = 0; j < 32; j++) {
        c[j] += b[i][j];
      }
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 31; j >= 0; j--) {
        c[j] -= b[i][j];
      }
      for (int j = 31; j >= 0; j--) {
        if (b[i][j] == 1) {
          ans += c[j];
          break;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
