#include <bits/stdc++.h>
using namespace std;
long long inp;
long long i1, i2, i3, i4, i5, i6, i7, i8;
long long mov = (long long)1e9 + 7;
long long a, b, xab = 1, yab;
double eps = 1e-9;
vector<pair<long long, long long>> v;
long long ccw(pair<long long, long long> p1) {
  return p1.first * yab - p1.second * xab;
}
long long dtp(pair<long long, long long> p1) {
  return p1.first * xab + p1.second * yab;
}
bool crp(pair<long long, long long> p1, pair<long long, long long> p2) {
  long long crp1 = p1.first * yab - p1.second * xab;
  long long crp2 = p2.first * yab - p2.second * xab;
  if (crp1 != crp2) {
    return crp1 > crp2;
  }
  return p1.first * xab + p1.second * yab > p2.first * xab + p2.first * yab;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  long long n;
  cin >> n;
  cin >> a >> b;
  yab = a;
  for (long long i = (0); i < (n); i++) {
    long long trash, x, y;
    cin >> trash >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end(), crp);
  long long res = 0;
  long long seq = 1, same = 1;
  for (long long i = (0); i < (n - 1); i++) {
    if (ccw(v.at(i)) == ccw(v.at(i + 1))) {
      if (dtp(v.at(i)) != dtp(v.at(i + 1))) {
        same = 1;
        seq++;
        res += seq - same;
      } else {
        same++;
        seq++;
        res += seq - same;
      }
    } else {
      same = 1;
      seq = 1;
    }
  }
  cout << 2 * res;
  return 0;
}
