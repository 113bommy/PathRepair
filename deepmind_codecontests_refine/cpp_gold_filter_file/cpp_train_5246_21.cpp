#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
bool ispalindrome(string s) {
  long long int len = s.length();
  for (long long int i = 0; i < len; i++) {
    if (s[i] != s[len - i - 1]) return false;
  }
  return true;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = ((res) * (a));
    a = ((a) * (a));
    b >>= 1;
  }
  return res;
}
long long is_prime(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  for (i = 0; i < n; i++) {
    if (s[i] != '.') break;
  }
  int j = i;
  while (s[j] != '.') {
    j++;
  }
  j--;
  int r = 0, l = 0;
  for (int k = i; k <= j; k++) {
    if (s[k] == 'R')
      r++;
    else if (s[k] == 'L')
      l++;
  }
  if (r == j - i + 1)
    cout << i + 1 << " " << j + 2;
  else if (l == j - i + 1)
    cout << j + 1 << " " << i;
  else {
    int m = i;
    if (s[m] == 'R') {
      while (s[m] == 'R') m++;
      cout << i + 1 << " " << m;
    } else if (s[m] == 'L') {
      while (s[m] == 'L') m++;
      cout << m << " " << i + 1;
    }
  }
  return 0;
}
