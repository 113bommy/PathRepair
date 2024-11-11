#include <bits/stdc++.h>
using namespace std;
void printv(vector<long long int>& v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}
void printvv(vector<vector<long long int>>& vv) {
  for (auto x : vv) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
}
void printVS(vector<string> v) {
  for (auto x : v) {
    cout << x << endl;
  }
}
int gcd(int a, int b) {
  int R;
  while ((a % b) > 0) {
    R = a % b;
    a = b;
    b = R;
  }
  return b;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[10];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int nPrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  long long int fac[10];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[n - r], p) % p) % p;
}
void sieve(vector<long long int>& ans) {
  long long int n = 10000 + 5;
  bool prime[10000 + 5];
  for (long long int j = 0; j < n; j++) {
    prime[j] = true;
  }
  for (long long int p = 2; p * p < n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i < n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p < n; p++)
    if (prime[p]) ans.push_back(p);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
long long int countSetBits(long long int x) {
  long long int ans = 0;
  while (x > 0) {
    if (x % 2 == 1) ans++;
    x = x / 2;
  }
  return ans;
}
void swap(long long int& x, long long int& y) {
  long long int temp = x;
  x = y;
  y = temp;
  return;
}
void swap(vector<long long int>& x, vector<long long int>& y) {
  vector<long long int> temp = x;
  x = y;
  y = temp;
  return;
}
bool first(pair<long long int, long long int> pr1,
           pair<long long int, long long int> pr2) {
  return pr1.first < pr2.first;
}
int solve() {
  long long int n;
  cin >> n;
  string second;
  cin >> second;
  for (long long int j = 0; j < n - 1; j++) {
    if (second[j] != second[j + 1]) {
      cout << j + 1 << " " << j + 2 << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
