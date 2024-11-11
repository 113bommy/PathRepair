#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
long long toInt64(string s) {
  long long r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
double LOG(long long N, long long B) { return (log10l(N)) / (log10l(B)); }
string itoa(long long a) {
  if (a == 0) return "0";
  string ret;
  for (long long i = a; i > 0; i = i / 10) ret.push_back((i % 10) + 48);
  reverse(ret.begin(), ret.end());
  return ret;
}
vector<string> token(string a, string b) {
  const char *q = a.c_str();
  while (count(b.begin(), b.end(), *q)) q++;
  vector<string> oot;
  while (*q) {
    const char *e = q;
    while (*e && !count(b.begin(), b.end(), *e)) e++;
    oot.push_back(string(q, e));
    q = e;
    while (count(b.begin(), b.end(), *q)) q++;
  }
  return oot;
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
int check(int N, int pos) { return (N & (1 << pos)); }
int toggle(int N, int pos) {
  if (check(N, pos)) return N = reset(N, pos);
  return N = Set(N, pos);
}
void pbit(int N) {
  printf("(");
  for (int i = 10; i >= 0; i--) {
    bool x = check(N, i);
    cout << x;
  }
  puts(")");
}
int fx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int fy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
struct point {
  long long x, y;
  point(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
  point() {}
};
inline long long sqDist(const point &a, const point &b) {
  return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
vector<point> A, B;
vector<long long> l;
long long n, m, a, b;
double calc(int ia, int ib) {
  ia--;
  ib--;
  double D1 = sqrt(sqDist(point(0, 0), A[ia]));
  double D2 = sqrt(sqDist(A[ia], B[ib]));
  double D3 = l[ib];
  return D1 + D2 + D3;
  return 0;
}
double tern(int ib) {
  long long low = 1, high = A.size();
  long long d = 64;
  while (d--) {
    long long lt = (2 * low + high) / 3;
    long long rt = (low + 2 * high) / 3;
    if (calc(lt, ib) + 1e-9 > calc(rt, ib))
      low = lt;
    else
      high = rt;
  }
  long long idx = (low + high) / 2, idx2;
  double mn = 1e17;
  for (int i = max(1LL, idx - 10); i <= min(n, idx + 10); i++) {
    double ret = calc(i, ib);
    if (ret < mn) {
      mn = ret;
      idx2 = i;
    }
  }
  return calc(idx2, ib);
}
int main() {
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= (int)n; i++) {
    long long x = a, y;
    cin >> y;
    A.push_back(point(x, y));
  }
  for (int i = 1; i <= (int)m; i++) {
    long long x = b, y;
    cin >> y;
    B.push_back(point(x, y));
  }
  for (int i = 1; i <= (int)m; i++) {
    long long t;
    cin >> t;
    l.push_back(t);
  }
  double mn = 1e17, idx;
  for (int i = 1; i <= m; i++) {
    double ret = tern(i);
    if (ret < mn) {
      mn = ret;
      idx = i;
    }
  }
  int idx2;
  mn = 1e17;
  for (int i = 1; i <= n; i++) {
    double ret = calc(i, idx);
    if (ret < mn) {
      mn = ret;
      idx2 = i;
    }
  }
  cout << idx2 << " " << idx << endl;
}
