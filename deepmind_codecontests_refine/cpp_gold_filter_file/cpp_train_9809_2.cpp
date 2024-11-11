#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x;
  cin >> n >> x;
  string second;
  cin >> second;
  long long ans = 0;
  long long sm = 0;
  for (long long i = 0; i < n; i++) {
    if (second[i] == '0')
      sm++;
    else
      sm--;
  }
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    if (sm == 0 && c == x) {
      cout << -1 << endl;
      return;
    }
    if ((x - c) % sm == 0 && (x - c) / sm >= 0 && sm != 0) ans++;
    if (second[i] == '0')
      c++;
    else
      c--;
  }
  cout << ans << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
