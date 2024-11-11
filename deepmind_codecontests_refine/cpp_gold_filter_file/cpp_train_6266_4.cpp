#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int base = 19260817;
const int INF = 1e9;
const int maxn = 3e5 + 10;
const double eps = 1e-8;
inline int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
inline int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
inline int mul(int x, int y) { return 1LL * x * y % mod; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  set<long long> valid;
  valid.insert(1), valid.insert(2);
  long long now = 2;
  for (int i = 1; i <= 30; i++) {
    now *= 2;
    if (!(i & 1)) now--;
    valid.insert(now), valid.insert(++now);
  }
  int n;
  cin >> n;
  if (valid.find(n) != valid.end())
    cout << 1;
  else
    cout << 0;
  return 0;
}
