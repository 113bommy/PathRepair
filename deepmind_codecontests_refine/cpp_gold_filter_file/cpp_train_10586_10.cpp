#include <bits/stdc++.h>
using namespace std;
void printprecise(double l, long long int precision) {
  std::cout << std::fixed;
  std::cout << std::setprecision(precision);
  std::cout << l;
}
long long int ncr(long long int n, long long int k) {
  long long int C[n + 1][k + 1];
  long long int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  return C[n][k];
}
long long int power_wm(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int root(long long int x, vector<long long int> &roots) {
  if (roots[x] != x) roots[x] = root(roots[x], roots);
  return roots[x];
}
void unoin(long long int p, long long int q, vector<long long int> &roots,
           vector<long long int> &rank) {
  long long int rp = root(p, roots);
  long long int rq = root(q, roots);
  if (rank[rq] < rank[rp]) {
    roots[rq] = rp;
  } else if (rank[rp] > rank[rq]) {
    roots[rp] = rq;
  } else {
    roots[rp] = rq;
    rank[rq]++;
  }
}
long long int dig_sum(long long int n) {
  long long int s = 0;
  while (n) {
    s += n % 10;
    n /= 10;
  }
  return s;
}
long long int gcd(long long int a, long long int b) {
  if (a < b) {
    a = a + b;
    b = a - b;
    a = a - b;
  }
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int toD(long long int x, long long int y, long long int m) {
  return x * m + y % m;
}
pair<long long int, long long int> twoD(long long int p, long long int m) {
  return (make_pair(p / m, p % m));
}
vector<long long int> dist;
vector<vector<long long int> > g;
void dfs(long long int p) {
  if (dist[p] != -1) {
    return;
  }
  dist[p] = 0;
  long long int maxd = -1;
  for (long long int i = 0; i < g[p].size(); i++) {
    dfs(g[p][i]);
    maxd = max(maxd, dist[g[p][i]]);
  }
  dist[p] = maxd + 1;
}
vector<long long int> fact;
void calfact() {
  fact[0] = 1;
  for (long long int i = 1; i < 1000001; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<vector<pair<long long int, long long int> > > s(
      2, vector<pair<long long int, long long int> >(4));
  long long int x, y;
  for (long long int i = 0; i < 4; i++) {
    cin >> x >> y;
    x += 100;
    y += 100;
    s[0][i].first = x, s[0][i].second = y;
  }
  for (long long int i = 0; i < 4; i++) {
    cin >> x >> y;
    x += 100;
    y += 100;
    s[1][i].first = x, s[1][i].second = y;
  }
  sort((s[0]).begin(), (s[0]).end());
  sort((s[1]).begin(), (s[1]).end());
  long long int pll = 0;
  if (s[1][0].second == s[1][1].second) {
    pll = 1;
  }
  vector<vector<long long int> > plane(201, vector<long long int>(201));
  for (long long int i = s[pll][0].first; i < s[pll][3].first + 1; i++) {
    for (long long int j = s[pll][0].second; j < s[pll][1].second + 1; j++) {
      plane[i][j] = 1;
    }
  }
  long long int intersects = 0;
  long long int y1 = s[1 - pll][0].second;
  long long int x1 = s[1 - pll][0].first, x2 = s[1 - pll][3].first;
  for (long long int i = 0; i < s[1 - pll][1].first - s[1 - pll][0].first + 1;
       i++) {
    for (long long int j = y1 - i; j < y1 + i + 1; j++) {
      if (plane[x1 + i][j] || plane[x2 - i][j]) {
        intersects = 1;
        break;
      }
    }
    if (intersects) {
      break;
    }
  }
  cout << (intersects ? "YES" : "NO");
  return 0;
}
