#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string& s) {
  long long i = 0;
  long long j = s.size() - 1;
  while (i <= j)
    if (s[i++] != s[j--]) return false;
  return true;
}
long long modPow(long long a, long long b, long long mod) {
  while (b > 1) {
    if (b % 2 == 0) {
      a = a * a % mod;
      b /= 2;
    } else
      return a * modPow(a, b - 1, mod) % mod;
  }
  return a;
}
bool prime[2001];
void sieve() {
  prime[1] = false;
  for (long long i = 2; i * i < 2001; i++) {
    if (prime[i]) {
      for (long long j = i * i; j < 2001; j += i) prime[j] = false;
    }
  }
}
signed main() {
  string s;
  cin >> s;
  long long n = s.size();
  string result;
  long long i = 0;
  long long j = n - 1;
  vector<char> f, b;
  while (j - i >= 3) {
    if (s[i] == s[j]) {
      f.push_back(s[i]);
      b.push_back(s[j]);
      j -= 2;
      i += 2;
    } else if (s[i] == s[j - 1]) {
      f.push_back(s[i]);
      b.push_back(s[j - 1]);
      j -= 2;
      i += 2;
    } else if (s[i + 1] == s[j]) {
      f.push_back(s[i + 1]);
      b.push_back(s[j]);
      i += 2;
      j -= 2;
    } else {
      f.push_back(s[i + 1]);
      b.push_back(s[j + 1]);
      j -= 2;
      i += 2;
    }
  }
  for (char c : f) cout << c;
  if (i < j) cout << s[i];
  reverse(b.begin(), b.end());
  for (char c : b) cout << c;
}
