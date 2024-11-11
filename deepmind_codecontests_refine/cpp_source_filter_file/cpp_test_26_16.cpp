#include <bits/stdc++.h>
using namespace std;
unsigned long long fac(const unsigned long long& n) {
  unsigned long long ans = 1;
  for (int i = 3; i <= n; i++) {
    ans = (ans * i) % 1000000007;
  }
  return ans;
}
int main() {
  unsigned long long t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;
    cout << ((fac(2 * n)));
  }
}
