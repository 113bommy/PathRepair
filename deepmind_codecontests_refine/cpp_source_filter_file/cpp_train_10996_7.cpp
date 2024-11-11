#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const long long int INF = 1e18;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int cas = 1;
bool check(int x) {
  while (x) {
    if (x % 10 != 9) return false;
    x /= 10;
  }
  return true;
}
int caldigit(int x) {
  int res = 0;
  while (x) {
    x /= 10;
    res++;
  }
  return res;
}
long long int qpow(long long int x, long long int y) {
  long long int res = 1;
  while (y) {
    if (y & 1) res *= x;
    x *= x;
    y >>= 1;
  }
  return res;
}
void solve() {
  int n;
  while (cin >> n) {
    long long int sum = n + n - 1;
    if (n < 5) {
      cout << n * (n - 1) / 2 << endl;
      continue;
    }
    if (check(sum)) {
      cout << 1 << endl;
      continue;
    }
    long long int ans = 0;
    int pos = caldigit(sum) - 1;
    long long int num = qpow(10, pos) - 1;
    while (num <= sum) {
      if (num < n)
        ans += num / 2;
      else
        ans += n - num / 2;
      num += qpow(10, pos);
    }
    cout << ans << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
