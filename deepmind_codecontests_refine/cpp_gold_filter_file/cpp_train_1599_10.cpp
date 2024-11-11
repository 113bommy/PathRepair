#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  int n;
  cin >> n;
  long long a[2] = {0ll};
  for (int i = 0; i < n; i++) {
    a[i & 1] = (a[0] + a[1] + 1) % mod;
  }
  cout << (a[1] + a[0]) % mod;
}
