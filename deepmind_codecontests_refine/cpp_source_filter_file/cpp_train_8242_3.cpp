#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long double PI = acos((long double)-1);
inline int Get_bit(int x, int k) { return (x >> (k - 1)) & 1; }
inline long long Gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long Lcm(long long a, long long b) { return a / Gcd(a, b) * b; }
inline long long Pow(long long n, long long k) {
  long long r = 1;
  for (; k; k >>= 1, n = n * n % MOD) {
    if (k & 1) r = r * n % MOD;
  }
  return r;
}
const int base = 311;
const int N = 1e5 + 5;
long long n, m, k, query;
vector<int> vx[N], vy[N];
int dx[N], dy[N];
void Solve() {
  cin >> m >> n >> k;
  for (int i = 1; i <= m; i++) {
    vx[i].push_back(n + 1);
    vx[i].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    vy[i].push_back(m + 1);
    vy[i].push_back(0);
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    vx[x].push_back(y);
    vy[y].push_back(x);
  }
  for (int i = 1; i <= m; i++) {
    sort((vx[i]).begin(), (vx[i]).end());
  }
  for (int i = 1; i <= n; i++) {
    sort((vy[i]).begin(), (vy[i]).end());
  }
  int X = 1, Y = 1;
  int mv = 1;
  int r = n + 1, l = 0, d = m + 1, u = 0;
  long long cnt = 1;
  while (1) {
    if (mv == 1) {
      int g = vx[X][int(upper_bound((vx[X]).begin(), (vx[X]).end(), Y) -
                        vx[X].begin())];
      int y = min(r, g) - 1;
      if (y == Y) break;
      cnt += y - Y;
      Y = y;
      mv = 2;
      r = min(r, Y);
      u = X;
    }
    if (mv == 2) {
      int g = vy[Y][int(upper_bound((vy[Y]).begin(), (vy[Y]).end(), X) -
                        vy[Y].begin())];
      int x = min(d, g) - 1;
      if (x == X) break;
      cnt += x - X;
      X = x;
      mv = 3;
      d = min(d, X);
      r = Y;
    }
    if (mv == 3) {
      int g = vx[X][int(upper_bound((vx[X]).begin(), (vx[X]).end(), Y) -
                        vx[X].begin()) -
                    1];
      int y = max(l, g) + 1;
      if (y == Y) break;
      cnt += Y - y;
      Y = y;
      mv = 4;
      l = max(l, Y);
      d = X;
    }
    if (mv == 4) {
      int g = vy[Y][int(upper_bound((vy[Y]).begin(), (vy[Y]).end(), X) -
                        vy[Y].begin()) -
                    1];
      int x = max(u, g) + 1;
      if (x == X) break;
      cnt += X - x;
      X = x;
      mv = 1;
      u = max(u, X);
      l = Y;
    }
  }
  if (cnt >= n * m - k)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(10);
  Solve();
}
