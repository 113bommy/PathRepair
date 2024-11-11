#include <bits/stdc++.h>
using namespace std;
const int base = 1e9 + 75;
int n, a[109];
bool ok = true;
void check(int k, int t) {
  if (k == n + 1) {
    if (t % 2 == 1) {
      ok = false;
    }
    return;
  }
  if (ok)
    for (int i = n; i >= k; i--) {
      if (ok)
        if (a[i] % 2 == 1 && a[i + 1] % 2 == 1 && (i - k + 1) % 2 == 1) {
          check(i + 1, t + 1);
        }
    }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[n + 1] = 1;
  if (a[1] % 2 && a[n] % 2 && n % 2 == 1) {
    check(1, 0);
  }
  if (ok)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
