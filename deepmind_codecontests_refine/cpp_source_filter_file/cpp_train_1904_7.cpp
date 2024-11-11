#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    s += a;
  }
  if (s <= k)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t-- > 0) {
    solve();
    cout << "\n";
  }
  return 0;
}
