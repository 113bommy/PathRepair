#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
long long a, b;
inline long long calcMin(long long n, long long p) {
  if (p > n || p <= 0) return INF;
  return (n / p + 1) * (n / p + 1) * (n % p) + (n / p) * (n / p) * (p - n % p);
}
inline long long calcMax(long long n, long long p) {
  if (p > n || p <= 0) return -INF;
  return (p - 1) + (n - p + 1) * (n - p + 1);
}
inline string repeat(string c, long long t) {
  string s;
  for (long long i = 0; i < t; i++) s += c;
  ;
  ;
  ;
  return s;
}
vector<string> sa, sb;
void show(long long x, long long y) {
  ;
  ;
  for (long long i = 0; i < x; i++)
    sa.push_back(repeat("o", i == 0 || x == 1 ? a - x + 1 : 1));
  for (long long i = 0; i < y; i++)
    sb.push_back(repeat("x", b / y + (i < (b % y))));
  ;
  ;
  long long m = min(x, y);
  if (y > m) cout << sb[y - 1];
  for (long long i = 0; i < m; i++) cout << sa[i] << sb[i];
  if (x > m) cout << sa[x - 1];
  puts("");
}
int main() {
  cin >> a >> b;
  if (a == 0) {
    cout << -b * b << endl;
    cout << repeat("x", b);
    return 0;
  } else if (b == 0) {
    cout << a * a << endl;
    cout << repeat("o", a);
    return 0;
  }
  long long p = min(a, b);
  long long ans = -INF;
  long long ansi, ansj;
  for (long long i = 1; i <= p; i++) {
    for (long long j = i - 1; j <= i + 1; j++) {
      long long nans = calcMax(a, i) - calcMin(b, j);
      ;
      ;
      ;
      if (nans > ans) {
        ans = nans;
        ansi = i;
        ansj = j;
      }
    }
  }
  cout << ans << endl;
  show(ansi, ansj);
  return 0;
}
