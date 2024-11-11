#include <bits/stdc++.h>
const int md = 1e9 + 7;
const long long hs = 199;
using namespace std;
int n, a[100000];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 3; i <= n; i++) {
    if (n % i == 0) {
      for (int j = 0; j < n / i; j++) {
        bool good = true;
        for (int k = j; k < n; k += n / i) good = good && (a[k] == 1);
        if (good) return cout << "YES" << '\n', 0;
      }
    }
  }
  return cout << "NO" << '\n', 0;
}
