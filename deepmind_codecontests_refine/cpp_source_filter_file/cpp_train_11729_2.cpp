#include <bits/stdc++.h>
using namespace std;
int n;
int a[256], b[256], c[256], ra, rb, rc;
string p, q, r;
int main() {
  cin >> n >> p >> q >> r;
  for (char x : p) ra = max(ra, ++a[x]);
  for (char x : q) rb = max(rb, ++b[x]);
  for (char x : r) rc = max(rc, ++c[x]);
  if (n == 1 && ra == p.length()) p.pop_back();
  if (n == 1 && rb == q.length()) q.pop_back();
  if (n == 1 && rc == r.length()) r.pop_back();
  ra = min(ra + n, (int)p.length());
  rb = min(rb + n, (int)q.length());
  rc = min(rc + n, (int)r.length());
  if (ra > rb && ra > rc) {
    cout << "Kuroo" << endl;
    return 0;
  }
  if (rb > ra && rb > rc) {
    cout << "Shiro" << endl;
    return 0;
  }
  if (rc > ra && rc > rb) {
    cout << "Katie" << endl;
    return 0;
  }
  cout << "Draw" << endl;
  return 0;
}
