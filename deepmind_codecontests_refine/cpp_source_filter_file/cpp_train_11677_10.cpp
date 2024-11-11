#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n / 2 + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        cout << i << " " << j << '\n';
        cout << n + 1 - i << " " << m + 1 - j << '\n';
      }
    }
    if (n % 2) {
      for (int i = 0; i < n / 2; i++) {
        cout << n / 2 + 1 << " " << i + 1 << '\n';
        cout << n / 2 + 1 << " " << m + 1 - (i + 1) << '\n';
      }
      if (m % 2) cout << n / 2 + 1 << " " << m / 2 + 1 << '\n';
    }
  }
}
