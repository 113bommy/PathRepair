#include <bits/stdc++.h>
using namespace std;
bool is_Palindrome(string s) {
  long long m = s.length();
  for (long long i = 0; i < m / 2; i++) {
    if (s[i] != s[m - i - 1]) return 0;
  }
  return 1;
}
bool is_prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
const long long MOD = 1000000000;
const long long MAX = 100005;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long x = (n * (k - 1)) / k;
  for (long long i = x;; i++) {
    long long sum = i, p = k;
    while (i / p != 0) {
      sum += i / p;
      p *= k;
    }
    if (sum >= n) {
      cout << i;
      break;
    }
  }
  return 0;
}
