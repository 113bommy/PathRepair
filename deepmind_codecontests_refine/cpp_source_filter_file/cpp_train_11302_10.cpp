#include <bits/stdc++.h>
using namespace std;
pair<char, long long> hf, hb, df, db, sdf, sdb, vu, vd;
void h(long long x, long long y, long long x0, long long y0, char t) {
  if (x > x0 && x < hf.second && y == y0) {
    hf.first = t;
    hf.second = x;
  }
  if (x < x0 && x > hb.second && y == y0) {
    hb.first = t;
    hb.second = x;
  }
}
void v(long long x, long long y, long long x0, long long y0, char t) {
  if (y > y0 && y < vu.second && x == x0) {
    hf.first = t;
    hf.second = y;
  }
  if (y < y0 && y > vu.second && x == x0) {
    hb.first = t;
    hb.second = y;
  }
}
void md(long long x, long long y, long long x0, long long y0, char t) {
  if (x0 - x == y0 - y) {
    if (x0 > x && abs(x0 - x) < db.second) {
      db.first = t;
      db.second = abs(x0 - x);
    }
    if (x0 < x && abs(x0 - x) < df.second) {
      df.first = t;
      df.second = abs(x0 - x);
    }
  }
}
void md2(long long x, long long y, long long x0, long long y0, char t) {
  if (x0 - x == -(y0 - y)) {
    if (x0 > x && abs(x0 - x) < sdb.second) {
      sdb.first = t;
      sdb.second = abs(x0 - x);
    }
    if (x0 < x && abs(x0 - x) < sdf.second) {
      sdf.first = t;
      sdf.second = abs(x0 - x);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  hf.first = 'B';
  hb.first = 'B';
  vu.first = 'B';
  vd.first = 'B';
  sdb.first = 'R';
  sdf.first = 'R';
  df.first = 'R';
  db.first = 'R';
  hf.second = 10000000000000000;
  hb.second = -10000000000000000;
  vu.second = 10000000000000000;
  vd.second = -10000000000000000;
  db.second = 10000000000000000;
  df.second = 10000000000000000;
  sdf.second = 10000000000000000;
  sdb.second = 10000000000000000;
  long long x, y;
  cin >> x >> y;
  for (long long i = 0; i < n; i++) {
    char ch;
    long long a, b;
    cin >> ch >> a >> b;
    h(a, b, x, y, ch);
    v(a, b, x, y, ch);
    md(a, b, x, y, ch);
    md2(a, b, x, y, ch);
  }
  if (hf.first == 'R' || hf.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (hb.first == 'R' || hb.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (vu.first == 'R' || vu.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (vd.first == 'R' || vd.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (sdf.first == 'B' || sdf.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (sdb.first == 'B' || sdb.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (df.first == 'B' || df.first == 'Q') {
    cout << "YES";
    return 0;
  }
  if (db.first == 'B' || db.first == 'Q') {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
