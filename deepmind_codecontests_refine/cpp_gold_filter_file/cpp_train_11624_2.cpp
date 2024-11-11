#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 1;
const int MAX = 200001;
const long long MOD = 1000000007;
struct trio {
  int first;
  int second;
  int third;
};
struct long_trio {
  long long first;
  long long second;
  long long third;
};
double dist_point_line(int x1, int y1, int x2, int y2, int x3, int y3) {
  double distance = abs((y3 - y1) * x2 - (x3 - x1) * y2 + x3 * y1 - x1 * y3) /
                    (2 * sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)));
  return distance;
}
double dist_point_point(int x1, int y1, int x2, int y2) {
  double distance = sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
  return distance;
}
long long inq(long long k, long long q) {
  if (q == 0) return 1;
  long long l = inq(k, q / 2);
  if (q % 2 == 0)
    return l * l % MOD;
  else
    return l * l * k % MOD;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long cubr(long long a) {
  long long l = -1, r = 1e6 + 2;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (mid * mid * mid > a)
      r = mid;
    else
      l = mid;
  }
  return l;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return -1 * max(-a, -b); }
long long possible(long long q) {
  if (q == INF) return -1;
  return q;
}
string months[12] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long fact[13] = {1,    1,     2,      6,       24,       120,      720,
                      5040, 40320, 362280, 3622800, 39916800, 479001600};
int cx[6] = {1, -1, 0, 0, 0, 0};
int cy[6] = {0, 0, 1, -1, 0, 0};
int cz[6] = {0, 0, 0, 0, 1, -1};
long long n, m, x, y, k, ans = -1;
string s;
long long a[500000], white[500000], orange[500000], red[500000], a1[500000],
    a2[500000], a3[500000];
int main() {
  cin >> n >> k;
  int w = 0, o = 0, r = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'O') {
      orange[o] = a[i];
      o++;
    }
    if (s[i] == 'R') {
      red[r] = a[i];
      r++;
    }
    if (s[i] == 'W') {
      white[w] = a[i];
      w++;
    }
  }
  sort(white, white + w);
  sort(red, red + r);
  sort(orange, orange + o);
  if (r + o < k && w + o < k) {
    cout << -1;
    return 0;
  }
  if (o == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < w; i++) {
    a1[i + 1] = a1[i] + white[i];
  }
  for (int i = 0; i < o; i++) {
    a2[i + 1] = a2[i] + orange[i];
  }
  for (int i = 0; i < r; i++) {
    a3[i + 1] = a3[i] + red[i];
  }
  for (int cw = 1; cw < k; cw++) {
    int co = k - cw;
    if (co > o) continue;
    if (cw > w) continue;
    long long white_beauty = a1[w] - a1[w - cw];
    long long orange_beauty = a2[o] - a2[o - co];
    ans = max(ans, white_beauty + orange_beauty);
  }
  for (int cr = 1; cr < k; cr++) {
    int co = k - cr;
    if (co > o) continue;
    if (cr > r) continue;
    long long red_beauty = a3[r] - a3[r - cr];
    long long orange_beauty = a2[o] - a2[o - co];
    ans = max(ans, red_beauty + orange_beauty);
  }
  cout << ans;
}
