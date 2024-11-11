#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) a[i] = (i + a[i] % n + n) % n;
    sort(a, a + n);
    bool ok = 1;
    for (int i = 1; i < n; i++)
      if (a[i] == a[i - 1]) ok = 0;
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
