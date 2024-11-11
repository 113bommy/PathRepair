#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long b = 0;
  long long step = 0;
  long long n = s.length();
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == 'b') {
      b = (b + 1) % mod;
    } else {
      step = (step % mod + b % mod) % mod;
      b = (b % mod * 2 & mod) % mod;
    }
  }
  cout << step;
}
