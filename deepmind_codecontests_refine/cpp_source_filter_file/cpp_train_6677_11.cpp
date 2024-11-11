#include <bits/stdc++.h>
using namespace std;
int q;
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (n & 1) {
    if (a * 2 < b)
      cout << a * n + a << endl;
    else
      cout << (n / 2) * b + a << endl;
  } else {
    a <<= 1;
    cout << min(a, b) * (n / 2) << endl;
  }
}
int main() {
  cin >> q;
  while (q--) solve();
}
