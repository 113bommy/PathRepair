#include <bits/stdc++.h>
using namespace std;
class pas {
 public:
  long long x, y;
  pas(long long x = 0, long long y = 0) : x(x), y(y) {}
  pas operator+(pas p) { return pas(x + p.x, y + p.y); }
  pas operator-(pas p) { return pas(x - p.x, y - p.y); }
  pas operator*(long long a) { return pas(x * a, y * a); }
  pas operator/(long long a) { return pas(x / a, y / a); }
  long long norm() { return x * x + y * y; }
  bool operator<(const pas &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const pas &p) const { return x == p.x && y == p.y; }
};
long long x[60] = {0};
vector<long long> wa, sa;
long long p[100][100];
map<long long, long long> ma;
long long n, k;
vector<long long> sosu, yakusu, kosu;
long long wareru(long long r) {
  if (k % r != 0) return 0;
  long long sai = (n / r) * r;
  sai = ((r + sai) * (sai / r) / 2) % 1000000007;
  return sai;
}
char c[5030];
long long dp[2][5030] = {0};
vector<pas> ve, ve2;
signed main() {
  string s;
  cin >> s;
  long long l = s.length();
  long long d = s[0] - 'a';
  long long cn = 0;
  for (long long i = 0; i < l; i++) {
    if (d == (s[i] - 'a')) {
      cn++;
    } else {
      ve.push_back({cn, d});
      d = s[i] - 'a';
      cn = 1;
    }
  }
  ve.push_back({cn, d});
  long long ans = 0;
  while (1) {
    if (ve.size() <= 1) break;
    ve2.clear();
    long long ka = 0;
    for (long long i = 0; i < ve.size(); i++) {
      if (i == 0 || i == ve.size() - 1)
        ve[i].x--;
      else
        ve[i].x -= 2;
      if (ve[i].x < 0) ve[i].x = 0;
      if (ve[i].x == 0) ka++;
    }
    if (ka < 2) {
      cout << ans + 1 << endl;
      return 0;
    }
    long long g = 0;
    while (ve[g].x == 0) g++;
    pas z = {0, ve[g].y};
    while (1) {
      if (ve[g].y == z.y) {
        z.x += ve[g].x;
      } else if (z.x > 0) {
        ve2.push_back(z);
        z = ve[g];
      }
      g++;
      while (g != ve.size() && ve[g].x <= 0) g++;
      if (g == ve.size()) {
        ve2.push_back(z);
        break;
      }
    }
    ans++;
    ve = ve2;
  }
  cout << ans << endl;
}
