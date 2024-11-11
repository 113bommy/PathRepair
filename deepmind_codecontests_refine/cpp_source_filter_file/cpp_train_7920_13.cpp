#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 7;
const long double EPS = 1e-8;
const long long MAXI = 20000;
const long long MOD = 16714589;
const long long MAXST = 2000000;
const long double PI = 3.14159265358979323;
ostream &operator<<(ostream &stream, const pair<long long, long long> &p) {
  stream << p.first << ' ' << p.second << ' ';
  return stream;
}
bool u[30];
signed main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
  long long n, m;
  cin >> m >> n;
  for (long long i = 0; i < n; i++) {
    cout << m << '\n';
    cout.flush();
    long long x;
    cin >> x;
    if (x == 0 || x == -2)
      exit(0);
    else if (x == 1)
      u[i] = true;
    else
      u[i] = false;
  }
  long long left = 1, right = m;
  for (long long i = 0; left < right - 1; i++) {
    long long mid = (left + right) / 2;
    cout << mid << '\n';
    cout.flush();
    long long x;
    cin >> x;
    if (x == 0 || x == -2) exit(0);
    if (u[i]) {
      if (x == 1)
        right = mid;
      else
        left = mid;
    } else {
      if (x == 1)
        left = mid;
      else
        right = mid;
    }
  }
  cout << left << '\n';
  cout.flush();
  long long x;
  cin >> x;
  if (x == 0 || x == -2) exit(0);
  cout << right << '\n';
  cout.flush();
  cin >> x;
  if (x == 0 || x == -2) exit(0);
  return 0;
}
