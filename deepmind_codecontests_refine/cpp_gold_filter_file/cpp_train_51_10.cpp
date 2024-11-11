#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000001000;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const double PI = 3.1415926535897932;
double sqr(double first) { return first * first; };
long double sqr(long double first) { return first * first; };
long long sqr(long long first) { return first * first; };
long long sqr(int first) { return first * 1LL * first; };
long long gcd(long long a, long long b) {
  while (b) a %= b, swap(a, b);
  return a;
}
long long bpm(long long a, long long n = -2, long long m = mod) {
  n = n >= 0 ? n : m + n;
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return r;
}
long long dist(long long x1, long long y1, long long x2, long long y2) {
  return sqr(x1 - x2) + sqr(y1 - y2);
}
std::ostream& operator<<(std::ostream& os, pair<int, int> p) {
  return os << "{" << p.first << " " << p.second << "}";
}
const int N = 200005;
vector<long long> t, t2;
int n;
void init(int nn) {
  n = nn;
  t.assign(n, 0);
  t2.assign(n, 0);
}
long long sum(vector<long long>& t, int r) {
  long long result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    result += t[r];
  }
  return result;
}
void inc(vector<long long>& t, int i, int delta) {
  for (; i < n; i = (i | (i + 1))) t[i] += delta;
}
long long sum(vector<long long>& t, int l, int r) {
  return sum(t, r) - sum(t, l - 1);
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  ;
  init(n + 1);
  int a, b;
  scanf("%d %d", &a, &b);
  ;
  int tests;
  scanf("%d", &tests);
  for (int test = 0; test < tests; test++) {
    int tp;
    scanf("%d", &tp);
    if (tp == 1) {
      int d, first;
      scanf("%d %d", &d, &first);
      ;
      long long c = sum(t, d, d);
      long long c2 = sum(t2, d, d);
      inc(t, d, min(a - c, 1LL * first));
      inc(t2, d, min(b - c2, 1LL * first));
    } else {
      int d;
      scanf("%d", &d);
      long long res = 0;
      if (d > 1) {
        res += sum(t2, 1, d - 1);
      }
      if (d + k <= n) {
        res += sum(t, d + k, n);
      }
      cout << res << "\n";
    }
  }
  return 0;
}
