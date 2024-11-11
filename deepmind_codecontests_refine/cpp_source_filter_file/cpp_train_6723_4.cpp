#include <bits/stdc++.h>
using namespace std;
long long n, m, k, c, d;
int main() {
  cin >> n >> m;
  k = n - m;
  if (k & 1 || k < 0) {
    cout << -1;
    return 0;
  }
  k >>= 1;
  cout << k << ' ' << n - k << endl;
  return 0;
}
