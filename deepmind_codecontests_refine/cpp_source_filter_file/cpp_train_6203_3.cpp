#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int top_46prime[46] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
                       31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
                       73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
                       127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                       179, 181, 191, 193, 197, 199};
long long binpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    res = res * res % mod;
    b >>= 1;
  }
  return res;
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int extgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
const int MxN = 1000000;
int lp[MxN + 1];
vector<int> primes;
void cal_primes() {
  for (int i = 2; i <= MxN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0;
         j < (int)primes.size() && primes[j] <= lp[i] && i * primes[j] <= MxN;
         ++j) {
      lp[i * primes[j]] = primes[j];
    }
  }
}
int setBit(int set, int i) { return set | (1 << i); }
int unsetBit(int s, int i) { return s & ~(1 << i); }
bool isSet(int s, int i) { return s & (1 << i) != 0; }
int toggleBit(int s, int i) { return s ^ (1 << i); }
int setAll(int n) { return (1 << n) - 1; }
bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
vector<int> calculateZ(string x, string y) {
  string z = x + "#" + y;
  int n = z.length();
  vector<int> Z(n);
  int l = 0, r = 0, k;
  for (int i = 1; i < n; i++) {
    if (i > r) {
      l = r = i;
      while (r < n && z[r - l] == z[r]) {
        r++;
      }
      Z[i] = r - l;
      r--;
    } else {
      k = i - l;
      if (Z[k] < r - i + 1) {
        Z[i] = Z[k];
      } else {
        l = i;
        while (r < n && z[r - l] == z[r]) {
          r++;
        }
        Z[i] = r - l;
        r--;
      }
    }
  }
  return Z;
}
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  int dis[n + 5][m + 5];
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < m; j++) {
      dis[i][j] = INT_MAX;
      if (v[i][j] == 'X') {
        x = i, y = j;
        dis[i][j] = 0;
      }
    }
  }
  queue<pair<int, int> > q;
  q.push({x, y});
  while (!q.empty()) {
    int ax = q.front().first, ay = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextX = ax + dx[i], nextY = ay + dy[i];
      if (nextY >= 0 && nextY < m && nextX >= 0 && nextX < n &&
          v[nextX][nextY] != '*' && dis[nextX][nextY] == INT_MAX) {
        q.push({nextX, nextY});
        dis[nextX][nextY] = dis[ax][ay] + 1;
      }
    }
  }
  string res, zz = "DLRU";
  bool flag = true;
  while (k--) {
    bool check = false;
    for (int i = 0; i < 4; i++) {
      int ax = x + dx[i], ay = y + dy[i];
      if (ax >= 0 && ay >= 0 && ax < n && ay < m && v[ax][ay] != '*' &&
          dis[ax][ay] <= k) {
        check = true;
        res += zz[i];
        x = ax, y = ay;
        break;
      }
    }
    if (!check) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << res << endl;
  } else
    cout << "IMPOSSIBLE" << endl;
}
