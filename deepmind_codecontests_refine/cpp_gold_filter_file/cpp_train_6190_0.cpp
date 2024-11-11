#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);
const long long INF = 2e18;
template <typename T, typename T1>
void amax(T &a, T1 b) {
  if (b > a) a = b;
}
template <typename T, typename T1>
void amin(T &a, T1 b) {
  if (b < a) a = b;
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long modinv(long long a, long long m) { return power(a, m - 2, m); }
int TLE_TERROR() {
  long long n, p, f = 0, zz = -1;
  cin >> n >> p;
  string s;
  cin >> s;
  if (p == 1) {
    cout << "NO";
    return 0;
  }
  if (p == 2) {
    if (n > 2)
      cout << "NO";
    else if (n == 1) {
      if (s[0] == 'a')
        cout << 'b';
      else
        cout << "NO";
    } else {
      if (s == "ab")
        cout << "ba";
      else
        cout << "NO";
    }
    return 0;
  }
  for (long long i = n - 1; i >= 0; i--) {
    char z = s[i];
    while ((z - 'a' + 1) < p) {
      z++;
      if (i > 0 && z == s[i - 1]) continue;
      if (i > 1 && z == s[i - 2]) continue;
      long long q = n - i;
      s[i] = z;
      f = 1;
      zz = i;
      break;
    }
    if (f == 1) break;
  }
  if (f == 0)
    cout << "NO";
  else {
    for (long long i = zz + 1; i < n; i++) {
      if (i > 1) {
        if (s[i - 1] != 'a' && s[i - 2] != 'a')
          s[i] = 'a';
        else if (s[i - 1] != 'b' && s[i - 2] != 'b')
          s[i] = 'b';
        else
          s[i] = 'c';
      } else {
        if (s[i - 1] != 'a')
          s[i] = 'a';
        else if (s[i - 1] != 'b')
          s[i] = 'b';
        else
          s[i] = 'c';
      }
    }
    cout << s;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int TESTS = 1;
  while (TESTS--) TLE_TERROR();
  return 0;
}
