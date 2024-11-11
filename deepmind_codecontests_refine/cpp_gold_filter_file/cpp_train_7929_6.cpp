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
long long a[200], b[200];
map<long long, long long> kol;
signed main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  };
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    kol[a[i]]++;
  }
  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    kol[b[i]]++;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long x = a[i] + b[j];
      if (kol.find(x) == kol.end()) return cout << a[i] << ' ' << b[j], 0;
    }
  }
  return 0;
}
