#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long x) {
  if (x == 1) return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
bool is_palindrome(string s1) {
  int l = s1.length();
  for (int i = 0; i < l / 2; i++)
    if (s1[i] != s1[l - i - 1]) return false;
  return true;
}
long long modular_pow(long long base, long long exponent, int modulus) {
  long long result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % modulus;
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}
long long binaryToDec(string number) {
  long long result = 0, pow = 1;
  for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
    result = (result + (number[i] - '0') * pow) % 1000003;
  return result;
}
long long binaryToDec2(string number) {
  long long result = 0, pow = 1;
  int l = number.length();
  for (int i = 0; i < l; ++i, pow <<= 1)
    result = (result + (number[i] - '0') * pow) % 1000003;
  return result;
}
bool hh(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  return x.first.first < y.first.first ||
         x.first.first == y.first.first && x.first.second > y.first.second;
}
bool hhh(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
  return x.first.second > y.first.second ||
         x.first.second == y.first.second && x.first.first < y.first.first;
}
const int mx = 1e5 + 5;
long long dp[mx];
int main() {
  int n;
  cin >> n;
  vector<long long> iniii(n), ans;
  for (int i = 0; i < n; i++) cin >> iniii[i];
  for (int i = 1; i < n; i++) ans.push_back(abs(iniii[i] - iniii[i - 1]));
  long long l, r, tmp = 0;
  l = 0, r = 1e18;
  int it = 0;
  for (int i = 0; i < n - 1; i++) {
    if (i & 1)
      tmp -= ans[i];
    else
      tmp += ans[i];
    while (tmp < 0 && it <= i) {
      if (it & 1)
        tmp += ans[it++];
      else
        tmp -= ans[it++];
    }
    l = max(l, tmp);
  }
  tmp = 0, it = 0;
  for (int i = 0; i < n - 1; i++) {
    if (i & 1)
      tmp -= ans[i];
    else
      tmp += ans[i];
    while (tmp > 0 && it <= i) {
      if (it & 1)
        tmp += ans[it++];
      else
        tmp -= ans[it++];
    }
    r = min(r, tmp);
  }
  long long opt = l;
  if (r != 1e18) opt = max(opt, -r);
  cout << opt << endl;
}
