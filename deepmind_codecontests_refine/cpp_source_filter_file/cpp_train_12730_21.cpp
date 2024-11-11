#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
bool comp(long long int a, long long int b) { return a < b; }
long long int spow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
vector<long long int> sieve(long long int l, long long int r) {
  bool isPrime[r - l + 1];
  for (long long int i = 0; i <= r; i++) isPrime[i] = true;
  vector<long long int> v;
  for (long long int i = 2; i * i <= r; ++i) {
    for (long long int j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
      isPrime[j - l] = false;
    }
  }
  for (long long int i = max((int)l, 2); i <= r; ++i) {
    if (isPrime[i - l]) {
      v.push_back(i);
    }
  }
  return v;
}
int Eul_Toi(int n) {
  bool a[n + 1];
  for (int i = 0; i <= n; i++) a[i] = true;
  a[0] = false;
  a[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (a[i]) {
      for (int j = i * i; j <= n; j += i) a[j] = false;
    }
  }
  float pro = n;
  for (int i = 2; i <= n; i++) {
    if (a[i] == true && n % i == 0) {
      pro = pro * (1 - 1 / (float)i);
    }
  }
  return ((int)ceil(pro));
}
signed main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
      cout << 2 * i + 1 << " ";
    }
    cout << endl;
  }
}
