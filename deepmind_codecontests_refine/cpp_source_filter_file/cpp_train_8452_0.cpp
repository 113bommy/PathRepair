#include <bits/stdc++.h>
const long long MOD = 998244353;
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x, v, h;
    cin >> n >> x >> v >> h;
    cout << min((v - h) + x, n - 1) << "\n";
  }
}
