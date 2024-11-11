#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
void fun() {}
bool isPrime(long long n) {
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fun();
  long long tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long c = 0;
    for (long long i = 0; i < n; i++)
      if (s[i] == '?') c++;
    long long left = 0, right = 0, leftc = 0, rightc = 0;
    for (long long i = 0; i < n / 2; i++) {
      if (s[i] != '?')
        left += (s[i] - 48);
      else
        leftc++;
    }
    for (long long i = n / 2; i < n; i++) {
      if (s[i] != '?')
        right += (s[i] - 48);
      else
        rightc++;
    }
    if (!c and left == right) return cout << "Bicarp", 0;
    if (!c and left != right) return cout << "Monocarp", 0;
    if (leftc == rightc) {
      if (left == right)
        return cout << "Bicarp", 0;
      else if (left > right)
        return cout << "Monocarp", 0;
      else
        return cout << "Monocarp", 0;
    }
    if (leftc > rightc) {
      long long chances = rightc - leftc;
      long long diff = right - left;
      if (diff < 0)
        return cout << "Monocarp", 0;
      else {
        chances /= 2;
        if (diff == chances * 9)
          return cout << "Bicarp", 0;
        else
          return cout << "Monocarp", 0;
      }
    }
    if (rightc > leftc) {
      long long chances = rightc - leftc;
      long long diff = (left - right);
      if (diff < 0)
        return cout << "Monocarp", 0;
      else {
        chances /= 2;
        if (diff == chances * 9)
          return cout << "Bicarp", 0;
        else
          return cout << "Monocarp", 0;
      }
    }
  }
  return 0;
}
