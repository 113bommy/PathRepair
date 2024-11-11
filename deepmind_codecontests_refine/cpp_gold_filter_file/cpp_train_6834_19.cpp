#include <bits/stdc++.h>
using namespace std;
const long long int ifn = -1000000007;
const int N = 100000;
const long long int inf = (1LL << 60) - 1;
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
void swap(int x, int y) {
  int t = x;
  x = y;
  y = t;
}
bool vow(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  } else {
    return false;
  }
}
bool isPrime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int chek(string s, int i, int j) {
  long long int cnt = 0, k, a;
  for (k = i; k <= j; k++) {
    a = int(s[k]) - 48;
    cnt = (cnt * 10) + (a);
  }
  return cnt;
}
void solve() {
  int x;
  cin >> x;
  int i;
  if (x == 0)
    cout << -1;
  else if (x > 36)
    cout << -1;
  else if (x <= 36) {
    if (x % 2) {
      cout << 4;
      for (i = 1; i <= (x - 1) / 2; i++) cout << 8;
    } else {
      for (i = 1; i <= (x / 2); i++) cout << 8;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
