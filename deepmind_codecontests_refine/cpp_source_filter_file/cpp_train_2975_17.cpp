#include <bits/stdc++.h>
using namespace std;
void adskiy_razgon() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long double PI = acos((long double)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
long long nod(long long a, long long b) {
  if (b > a) {
    swap(a, b);
  }
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long nok(long long a, long long b) { return a * b / nod(a, b); }
void sp(long long a, double b) { cout << fixed << setprecision(a) << b; }
long long binpow(long long a, long long n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 1) {
    return binpow(a, n - 1) * a;
  } else {
    long long b = binpow(a, n / 2);
    return b * b;
  }
}
void solve() {
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  cout << 3 << endl;
  cout << bx + (ax - cx) << " " << by + (ay - cy) << endl;
  cout << ax + (bx - cx) << " " << ay + (cy - by) << endl;
  cout << cx + (ax - bx) << " " << cy + (ay - by) << endl;
}
int main() {
  adskiy_razgon();
  long long t = 1;
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
