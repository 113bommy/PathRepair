#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int mod1 = 998244353;
void swap(long long int &a, long long int &b) {
  long long int t = a;
  a = b;
  b = t;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int pow(long long int a, long long int b) {
  a %= mod;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return ans;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int mx = -1;
    long long int diff = -1;
    long long int flg = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(a[i], mx);
      diff = max(mx - a[i], diff);
      if (i != 0) {
        if (a[i] < a[i - 1]) {
          flg = 1;
        }
      }
    }
    if (flg == 0) {
      cout << 0 << "\n";
      continue;
    }
    long long int start = 0;
    long long int in = 0;
    while (diff) {
      diff /= 2;
      in++;
    }
    cout << in << "\n";
  }
}
