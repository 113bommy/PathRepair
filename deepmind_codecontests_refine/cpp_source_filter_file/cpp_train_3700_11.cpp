#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 51, MOD = 1e9 + 7;
const long double EPS = 0.000000001, PI = atan2(0, -1);
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, all = 0, kol = 0;
  cin >> n;
  map<long long, long long> Ildar_chsv;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    all += x;
    Ildar_chsv[x]++;
    kol = max(kol, Ildar_chsv[x]);
  }
  cout << n - kol;
}
