#include <bits/stdc++.h>
const double PI = 3.141592653589793238460;
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
long long pows(long long a, long long n, long long m) {
  a = a % m;
  long long res = 1;
  while (n) {
    if (n % 2 != 0) {
      res = (res * a) % m;
      n--;
    } else {
      a = (a * a) % m;
      n = n / 2;
    }
  }
  return res % m;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isprime(long long n) {
  if (n == 1 || n == 0) {
    return false;
  }
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
bool istrue(string s) {
  int i = 0;
  int j = s.size() - 1;
  while (i < j) {
    if (s[i] == s[j]) {
      i++;
      j--;
    } else {
      return false;
    }
  }
  return true;
}
const int N = 200005;
bool isPoss(string s, string t) {
  long long i = 0;
  long long j = 0;
  long long n = s.size();
  long long m = t.size();
  while (i < n && j < m) {
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      i++;
    }
  }
  if (j == m) {
    return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TT = clock();
  TT = clock();
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long idx = -1;
    for (long long i = 0; i < n; i++) {
      if (s[i] == '0') {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      cout << 1 << " " << n << " " << 2 << " " << n << "\n";
    } else {
      idx++;
      long long mid = n / 2;
      if (idx <= mid) {
        cout << idx << " " << n << " " << idx + 1 << " " << n << "\n";
      } else {
        cout << 0 << " " << idx << " " << 0 << " " << idx - 1 << "\n";
      }
    }
  }
  cerr << "\n\nTIME: " << (long double)(clock() - TT) / CLOCKS_PER_SEC
       << " sec\n";
  return 0;
}
