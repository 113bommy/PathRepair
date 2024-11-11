#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, h1, h2, a1, a2, x1, x2, y1, y2;
  cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
  bool ok = 0;
  long long t1 = 0;
  long long p1 = 0;
  long long t2 = 0;
  long long p2 = 0;
  for (int i = 0; i < 1000000; i++) {
    h1 *= x1;
    h1 += y1;
    h1 %= m;
    if (h1 == a1) {
      t1 = i + 1;
      ok = 1;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  ok = 0;
  for (int i = 0; i < 1000000; i++) {
    h1 *= x1;
    h1 += y1;
    h1 %= m;
    if (h1 == a1) {
      p1 = i + 1;
      ok = 1;
      break;
    }
  }
  ok = 0;
  for (int i = 0; i < 1000000; i++) {
    h2 *= x2;
    h2 += y2;
    h2 %= m;
    if (h2 == a2) {
      t2 = i + 1;
      ok = 1;
      break;
    }
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  ok = 0;
  for (int i = 0; i < 1000000; i++) {
    h2 *= x2;
    h2 += y2;
    h2 %= m;
    if (h2 == a2) {
      p2 = i + 1;
      ok = 1;
      break;
    }
  }
  ok = 0;
  for (int i = 0; i < (m << 1); i++) {
    if (t1 == t2) {
      ok = 1;
      break;
    }
    if (t1 < t2) {
      t1 += p1;
      continue;
    }
    t2 += p2;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  cout << t1 << endl;
  cin >> t1;
}
