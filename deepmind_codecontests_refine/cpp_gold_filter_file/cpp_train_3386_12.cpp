#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const long long LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const long long MOD = 1000000007;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const double PI = 3.141592653589793;
inline void fastll(long long &input_number) {
  input_number = 0;
  int ch = getchar_unlocked();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar_unlocked();
  }
  while (ch >= '0' && ch <= '9') {
    input_number = (input_number << 3) + (input_number << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  input_number *= sign;
}
inline void open(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
inline void fasterios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct dt {
  long long m, c;
};
long long gety(dt line, long long x) { return line.m * x + line.c; }
long double getintersection(dt linea, dt lineb) {
  return (long double)(linea.c - lineb.c) / (long double)(lineb.m - linea.m);
}
long long isi[200005];
long long sum[200005];
long long psum[200005];
long long n, ans, tot;
vector<dt> hull;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> isi[i];
    sum[i] = sum[i - 1] + isi[i];
    psum[i] = psum[i - 1] + (isi[i] * i);
  }
  ans = -LINF;
  for (long long i = n; i >= 1; i--) {
    dt nx = {-i, -sum[i]};
    while (hull.size() > 1) {
      long long blkg = hull.size() - 1;
      if (getintersection(nx, hull[blkg]) >
          getintersection(hull[blkg], hull[blkg - 1]))
        break;
      hull.pop_back();
    }
    hull.push_back(nx);
    long long kiri = 0;
    long long kanan = hull.size() - 1;
    while (kiri < kanan) {
      long long mid = (kiri + kanan) / 2;
      if (gety(hull[mid], -isi[i]) > gety(hull[mid + 1], -isi[i]))
        kanan = mid;
      else
        kiri = mid + 1;
    }
    ans = max(ans, gety(hull[kiri], -isi[i]) - (i * isi[i]) + sum[i]);
  }
  hull.clear();
  for (long long i = 1; i <= n; i++) {
    dt nx = {i, -sum[i - 1]};
    while (hull.size() > 1) {
      long long blkg = hull.size() - 1;
      if (getintersection(nx, hull[blkg]) >
          getintersection(hull[blkg], hull[blkg - 1]))
        break;
      hull.pop_back();
    }
    hull.push_back(nx);
    long long kiri = 0;
    long long kanan = hull.size() - 1;
    while (kiri < kanan) {
      long long mid = (kiri + kanan) / 2;
      if (gety(hull[mid], isi[i]) > gety(hull[mid + 1], isi[i]))
        kanan = mid;
      else
        kiri = mid + 1;
    }
    ans = max(ans, gety(hull[kiri], isi[i]) - (i * isi[i]) + sum[i - 1]);
  }
  cout << ans + psum[n] << '\n';
  return 0;
}
