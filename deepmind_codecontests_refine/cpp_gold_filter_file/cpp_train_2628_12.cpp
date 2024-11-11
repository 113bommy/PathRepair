#include <bits/stdc++.h>
using namespace std;
void result(bool first) {
  if (first)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    if (n == 2 && m == 2 || n == 1 || m == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
