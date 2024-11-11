#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXL = 20;
long long gcd(long long x, long long y) {
  if (!y) return x;
  return gcd(y, x % y);
}
long long lcm(long long x, long long y) { return x / gcd(x, y) * y; }
struct Rec {
  long long t;
  long long T;
  Rec() {}
  Rec(long long t, long long T) : t(t), T(T) {}
};
int n, m;
vector<vector<int> > a;
vector<pair<int, int> > p;
vector<int> k;
Rec table[MAXN][MAXL];
map<pair<int, int>, int> where;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
bool findAny(long long a, long long b, long long c, long long& x0,
             long long& y0, long long& g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g != 0) return false;
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 *= -1;
  if (b < 0) y0 *= -1;
  return true;
}
Rec combine(Rec r1, Rec r2) {
  if (r1.t == -1 || r2.t == -1) return Rec(-1, -1);
  long long a = r1.T;
  long long b = -r2.T;
  long long c = r2.t - r1.t;
  long long x, y, g;
  if (!findAny(a, b, c, x, y, g)) {
    return Rec(-1, -1);
  }
  long long T = lcm(r1.T, r2.T);
  long long shift = -b / g;
  if (x <= 0) {
    long long k = -x / shift;
    return Rec(r1.t + r1.T * (x + k * shift), T);
  } else {
    long long k = -(x + shift - 1) / shift;
    return Rec(r1.t + r1.T * (x + k * shift), T);
  }
}
int main() {
  cin >> n >> m;
  k = vector<int>(n);
  a = vector<vector<int> >(n);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &k[i]);
    a[i] = vector<int>(k[i]);
    for (int j = 0; j < (int)(k[i]); j++) {
      scanf("%d", &a[i][j]);
      a[i][j]--;
      where[make_pair(i, a[i][j])] = j;
      p.push_back(make_pair(a[i][j], i));
    }
  }
  vector<int> ans(m);
  sort(p.begin(), p.end());
  int lf = 0;
  while (lf < p.size()) {
    int rg = lf + 1;
    while (rg < p.size() && p[lf].first == p[rg].first &&
           p[rg - 1].second + 1 == p[rg].second)
      rg++;
    int val = p[lf].first;
    int l = p[lf].second;
    int r = p[rg - 1].second + 1;
    for (int i = l; i < r; i++) {
      table[i][0] = Rec(where[make_pair(i, val)], k[i]);
    }
    for (int j = 1; (1 << j) <= r - l; j++) {
      for (int i = l; i + (1 << j) <= r; i++) {
        table[i][j] = combine(table[i][j - 1], table[i + (1 << j) / 2][j - 1]);
      }
    }
    for (int i = l; i < r; i++) {
      Rec cur(0, 1);
      int j = i;
      for (int k = MAXL - 1; k >= 0; k--) {
        if (j + (1 << k) > r) continue;
        Rec next = combine(cur, table[j][k]);
        if (next.t != -1) {
          cur = next;
          j += 1 << k;
        }
      }
      ans[val] = max(ans[val], j - i);
    }
    lf = rg;
  }
  for (int i = 0; i < (int)(m); i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
