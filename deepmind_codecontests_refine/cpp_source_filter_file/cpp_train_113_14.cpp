#include <bits/stdc++.h>
using namespace std;
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long c, d, f, curr, pre;
void equal() {
  d -= (1 << curr);
  cout << "? " << c << " " << d << endl;
  cin >> f;
  if (f > 0) c -= (1 << curr);
  if (f < 0) d += (1 << curr);
  pre = 0;
}
void ggreater() {
  cout << "? " << c << " " << d << endl;
  cin >> f;
  if (f < 0) {
    d -= (1 << curr);
    cout << "? " << c << " " << d << endl;
    cin >> pre;
  } else {
    c -= (1 << curr);
    cout << "? " << c << " " << d << endl;
    cin >> f;
    pre = 1;
    if (f > 0) c += (1 << curr);
    if (f < 0) d -= (1 << curr);
  }
}
void samaller() {
  cout << "? " << c << " " << d << endl;
  cin >> f;
  if (f > 0) {
    c -= (1 << curr);
    cout << "? " << c << " " << d << endl;
    cin >> pre;
  } else {
    d -= (1 << curr);
    cout << "? " << c << " " << d << endl;
    cin >> f;
    pre = 0;
    if (f < 0) d += (1 << curr);
    if (f > 0) c -= (1 << curr);
  }
}
void solve() {
  curr = 30;
  cout << "?" << c << " " << d << endl;
  cin >> pre;
  c = (1 << curr), d = (1 << curr);
  while (curr >= 0) {
    if (pre == 0)
      equal();
    else if (pre == 1)
      ggreater();
    else
      samaller();
    curr--;
    if (curr >= 0) c += (1 << curr), d += (1 << curr);
  }
  cout << "! " << c << " " << d << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  start = clock();
  cout << fixed << setprecision(15);
  while (t--) {
    solve();
  }
  double time_taken = double(clock() - start) / double(CLOCKS_PER_SEC);
  cerr << time_taken;
}
