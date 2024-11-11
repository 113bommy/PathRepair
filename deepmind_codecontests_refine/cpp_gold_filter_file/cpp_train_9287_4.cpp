#include <bits/stdc++.h>
using namespace std;
void solve(long long n, long long d) {
  long long i;
  if (d <= n) {
    cout << "YES" << endl;
    return;
  }
  for (i = 1; i <= n; i++) {
    long long x = i + ceil(1.0 * d / (i + 1));
    if (x <= n) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, d;
    cin >> n >> d;
    solve(n, d);
  }
}
