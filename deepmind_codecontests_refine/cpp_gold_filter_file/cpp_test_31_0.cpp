#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
signed long long power_binaryexp(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a);
    }
    a = (a * a);
    b = b >> 1;
  }
  return ans;
}
signed long long binarymul(long long a, long long b) {
  long long ans = 0;
  while (b) {
    if (b & 1) {
      ans = ans + a;
    }
    a += a;
    b >>= 1;
  }
  return ans;
}
bool is_prime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
bool compare(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second > p2.second;
}
bool checkp(string s) {
  long long n = s.length();
  for (long long i = 0; i < n / 2; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long ttt;
  cin >> ttt;
  while (ttt--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    long long sum = 0;
    long long s = 0;
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<long long> v1(n);
    if (n & 1) {
      if (v[1] < 0)
        v1[1] = -abs(v[0]);
      else
        v1[1] = abs(v[0]);
      if (v[2] < 0)
        v1[2] = -abs(v[0]);
      else
        v1[2] = abs(v[0]);
      s = (v[1] * v1[1] + v1[2] * v[2]);
      if (v[0] < 0) {
        s = -s;
        v[0] = -v[0];
      }
      v1[0] = -s / v[0];
      if (v[0] < 0) n = -n;
      for (long long i = 3; i < n; i += 2) {
        v1[i] = v[i + 1];
        v1[i + 1] = -v[i];
      }
    } else {
      for (long long i = 0; i < n; i += 2) {
        v1[i] = v[i + 1];
        v1[i + 1] = -v[i];
      }
    }
    for (auto x : v1) {
      cout << x << " ";
    }
    cout << endl;
  }
}
