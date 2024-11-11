#include <bits/stdc++.h>
using namespace std;
long long int bpow(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % 1000000007;
    b /= 2;
    a = (a * a) % 1000000007;
  }
  return ans;
}
int main() {
  long long int testc;
  cin >> testc;
  while (testc--) {
    long long int n;
    cin >> n;
    cout << 2 << " " << n / 2 << "\n";
  }
}
