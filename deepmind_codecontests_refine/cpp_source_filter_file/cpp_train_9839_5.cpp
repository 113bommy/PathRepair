#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long s;
    s = n * (n + 1) / 2;
    for (int i = 1; i <= n; i <<= 2) s -= 2 * i;
    cout << s << '\n';
  }
  return 0;
}
