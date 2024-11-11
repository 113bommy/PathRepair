#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250, MAXBS = 1000000;
const double PI = acos(-1);
struct dot {
  long long x, y;
  dot(long long x = 0, long long y = 0) : x(x), y(y) {}
};
struct line {
  long long a, b, c;
  bool side(dot p) { return (a * p.x + b * p.y > -c); }
};
int n, total;
dot A, B;
line l;
int main() {
  while (cin >> A.x >> A.y >> B.x >> B.y) {
    cin >> n;
    total = 0;
    for (int i = (0); i < (int)(n); i++) {
      cin >> l.a >> l.b >> l.c;
      if (l.side(A) != l.side(B)) total++;
    }
    cout << total << endl;
  }
  return 0;
}
