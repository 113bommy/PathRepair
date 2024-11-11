#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long double eps = 1e-9;
const long double pi = acos(-1.0);
int xabs(int x) { return x < 0 ? -x : x; }
struct see {
  int t, l, r;
  see() {}
  see(int t, int l, int r) : t(t), l(l), r(r) {}
};
int sign(int x) {
  if (x == 0) return 0;
  return x < 0 ? -1 : 1;
}
int main() {
  long long r, h;
  cin >> r >> h;
  h *= 2;
  r *= 2;
  long long cnt = 0;
  int c1 = (h + r / 2) / r;
  c1 *= 2;
  long long ost = (h + r / 2) % r;
  if ((ost + r / 2) * (ost + r / 2) + (r / 2) * (r / 2) >= r * r) c1 += 1;
  cout << c1 << endl;
  return 0;
}
