#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 10;
long long A[MAX];
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 << endl;
    for (long long i = 1; i <= n / 2; ++i) cout << "2 ";
    cout << endl;
  } else {
    if (n == 3)
      cout << "1" << endl << "3" << endl;
    else {
      cout << (n / 2) + 1 << endl;
      n -= 3;
      for (long long i = 1; i <= n / 2; ++i) cout << "2 ";
      cout << "3" << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  solve();
  return 0;
}
