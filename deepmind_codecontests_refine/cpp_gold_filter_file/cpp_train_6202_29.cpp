#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
const long double PI = 3.1415926536;
void bye() {
  cout << "\n";
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long s, x1, x2, t1, t2, p, d;
  long long tr1, tr2;
  cin >> s >> x1 >> x2 >> t2 >> t1 >> p >> d;
  if (x2 > x1) {
    tr1 = abs(x1 - x2) * t2;
    tr2 = 0;
    if (d == -1 && p <= x1) {
      tr2 += (abs(p - 0) * t2);
      tr2 += (abs(x1 - 0) * t2);
    } else if (p <= x1 && d == 1) {
      tr2 += (abs(p - x1) * t2);
    } else if (p > x1 && d == 1) {
      tr2 += (abs(s - p) * t2);
      tr2 += (abs(s - 0) * t2);
      tr2 += (abs(x1 - 0) * t2);
    } else if (p > x1 && d == -1) {
      tr2 += (abs(p - 0) * t2);
      tr2 += (abs(x1 - 0) * t2);
    }
  } else {
    tr1 = abs(x1 - x2) * t2;
    tr2 = 0;
    if (d == -1 && p < x1) {
      tr2 += (abs(p - 0) * t2);
      tr2 += (abs(s - 0) * t2);
      tr2 += (abs(s - x1) * t2);
    } else if (p <= x1 && d == 1) {
      tr2 += (abs(p - s) * t2);
      tr2 += (abs(x1 - s) * t2);
    } else if (p > x1 && d == 1) {
      tr2 += (abs(s - p) * t2);
      tr2 += (abs(s - x1) * t2);
    } else if (p > x1 && d == -1) {
      tr2 += (abs(p - x1) * t2);
    }
  }
  cout << min(abs(x2 - x1) * t1, tr1 + tr2);
  bye();
}
