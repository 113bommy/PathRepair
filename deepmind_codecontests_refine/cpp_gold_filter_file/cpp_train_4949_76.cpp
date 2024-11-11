#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool cmps(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second < p2.second;
}
int32_t main() {
  string a, b;
  cin >> a >> b;
  if (a == b)
    cout << a << endl;
  else
    cout << 1 << endl;
  return 0;
}
