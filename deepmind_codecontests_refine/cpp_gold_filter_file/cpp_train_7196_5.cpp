#include <bits/stdc++.h>
using namespace std;
bool ask(long long x, long long y) {
  cout << "? " << x << " " << y << endl;
  string s;
  cin >> s;
  return (s == "x");
}
int main() {
  string s;
  while (cin >> s && s == "start") {
    long long l0, r0;
    for (long i = 1; i <= (1 << 30); i *= 2) {
      long long r = i;
      long long l = r / 2;
      if (ask(l, r)) {
        l0 = l;
        r0 = r;
        break;
      }
    }
    long long l = l0 + 1, r = r0;
    while (l <= r) {
      long long mid = l + (r - l) / 2;
      if (ask(l0, mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << "! " << l << endl;
  }
}
