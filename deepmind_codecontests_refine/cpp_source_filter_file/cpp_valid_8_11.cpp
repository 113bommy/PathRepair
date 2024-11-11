#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "1 0";
    return;
  } else if (n == 2) {
    cout << "0 1";
    return;
  }
  long long a = n / 3;
  long long b = (n - a) / 2;
  if (a + b * 2 != n) {
    b++;
  }
  cout << a << ' ' << b;
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << "\n";
  }
  return 0;
}
