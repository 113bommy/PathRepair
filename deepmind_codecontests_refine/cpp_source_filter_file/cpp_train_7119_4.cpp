#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
struct date {
  int d, m, y;
} x, y, t1, t2;
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, c;
string a, b;
bool leap(int x) { return x % 400 == 0 || (x % 4 == 0 && x % 100); }
int main() {
  cin >> a >> b;
  for (int i = 0; i < 4; i++) {
    t1.y *= 10, t1.y += a[i] - '0';
    t2.y *= 10, t2.y += b[i] - '0';
  }
  t1.m = (a[5] - '0') * 10 + (a[6] - '0');
  t2.m = (b[5] - '0') * 10 + (b[6] - '0');
  t1.d = (a[8] - '0') * 10 + (a[9] - '0');
  t2.d = (b[8] - '0') * 10 + (b[9] - '0');
  if (t1.y > t2.y) swap(t1, t2);
  if (t1.y == t2.y) {
    if (t1.m > t2.m) swap(t1, t2);
    if (t1.m == t2.m && t1.d > t2.d) swap(t1, t2);
  }
  if (t1.y != t2.y) {
    if (t1.m <= 2) c = leap(t1.y);
    c -= t1.d;
    while (t1.m <= 12) c += mon[t1.m++];
    if (t2.m > 2) c += leap(t2.y);
    c += t2.d;
    while (--t2.m) c += mon[t2.m];
    while (++t1.y != t2.y) c += 365 + leap(t1.y);
  } else {
    if (t1.m <= 2 && t2.m > 2) c = leap(t1.y);
    c += t2.d - t1.d;
    while (++t1.m < t2.m) c += mon[t1.m];
  }
  cout << c;
  return 0;
}
