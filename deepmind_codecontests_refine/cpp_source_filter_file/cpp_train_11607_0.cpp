#include <bits/stdc++.h>
using namespace std;
template <typename T>
void setmax(T& x, T y) {
  x = max(x, y);
}
template <typename T>
void setmin(T& x, T y) {
  x = min(x, y);
}
template <typename T>
void print(const T& a, ostream& out) {
  for (auto i : a) out << i << ' ';
  out << endl;
}
const double PI = acos(-1.0);
const long long INF = 1e9 + 47;
const long long LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int xp, yp, xv, yv;
  cin >> xp >> yp >> xv >> yv;
  int ans1 = 0;
  int ans2 = 0;
  ans1 = xp + yp;
  ans2 = max(xv, yv);
  bool win = ans1 <= ans2;
  if (xp < xv && yp < yv) win = 1;
  if (win)
    cout << "Polycarp";
  else
    cout << "Vasiliy";
  cout << endl;
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
