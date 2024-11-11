#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool compare(pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
  if (a.first > b.first) return true;
  if (a.first == b.first) return a.second < b.second;
  return false;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
void solve() {
  long long int k;
  cin >> k;
  long long int n = 1;
  long long int i = 0;
  while (n + 2 * i + 1 <= k) {
    n += 2 * i + 1;
    i++;
  }
  if (n == k) {
    cout << 1 << " " << i << "\n";
    return;
  }
  int x = i + 1, y = 1;
  while (y != x) {
    y++;
    n++;
    if (n == k) {
      cout << y << " " << x << "\n";
      return;
    }
  }
  while (x >= 1) {
    x--;
    n++;
    if (n == k) {
      cout << y << " " << x << "\n";
      return;
    }
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
