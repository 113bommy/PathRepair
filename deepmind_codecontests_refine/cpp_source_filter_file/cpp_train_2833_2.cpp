#include <bits/stdc++.h>
using namespace std;
const int N = 2e7;
string str, t;
long long a[N];
const long long mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long times, n = 0, i;
    cin >> times >> str;
    for (auto x : str) a[++n] = x - '0';
    for (i = 1; i <= times; i++) {
      long long pn = n;
      for (long long j = 1; j < a[i]; j++)
        for (long long k = i + 1; k <= pn; k++) a[++n] = a[k];
      if (n >= times) break;
    }
    for (i++; i <= times; i++)
      n = (n + (((n - i) % mod) * ((a[i] - 1) % mod)) % mod) % mod;
    cout << n << endl;
  }
}
