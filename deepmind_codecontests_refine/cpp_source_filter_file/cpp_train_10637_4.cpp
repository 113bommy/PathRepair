#include <bits/stdc++.h>
using namespace std;
const long long MX = 500000;
const long long mod = 998244353;
const long long inf = 1e9;
long long sm[12];
long long pw[20];
string s;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, n, k, p, x;
  pw[0] = 1;
  for (i = 1; i < 20; i++) pw[i] = (pw[i - 1] * 10) % mod;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    for (j = 0; s[j]; j++) sm[j] += (s[j] - '0');
  }
  long long sum = 0;
  for (j = 0; j < s.size(); j++) {
    sum = (sum + (sm[j] * pw[(s.size() - j - 1) * 2 + 1]) % mod) % mod;
    sum = (sum + (sm[j] * pw[(s.size() - j - 1) * 2]) % mod) % mod;
  }
  cout << (sum * 3) % mod << endl;
  return 0;
}
