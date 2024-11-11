#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653689793238460;
const long long inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int pr = 31;
using ld = long double;
int mod = 998244353;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int power(long long x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool vis[2][10005];
int can[2][10005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s[2];
  cin >> s[0] >> s[1];
  queue<pair<int, int> > q;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    if (x + k >= n) {
      cout << "YES" << endl;
      return 0;
    }
    for (int ii = -1; ii <= 1; ii++) {
      if (x + ii > 0 && can[y][x] + 1 <= x + ii && !vis[y][x + ii] &&
          s[y][x + ii] == '-') {
        vis[y][x + ii] = true;
        can[y][x + ii] = can[y][x] + 1;
        q.push(make_pair(x + ii, y));
      }
    }
    if (!vis[1 - y][x + k] && s[1 - y][x + k] == '-') {
      vis[1 - y][x + k] = true;
      can[1 - y][x + k] = can[y][x] + 1;
      q.push(make_pair(x + k, 1 - y));
    }
  }
  cout << "NO" << endl;
}
