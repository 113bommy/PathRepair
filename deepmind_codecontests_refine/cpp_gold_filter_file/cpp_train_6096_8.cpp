#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T &a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T &a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxlg = 16;
const int maxn = (1 << maxlg) + 100;
int n;
int tx1, tx2, ty1, ty2;
int ask(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  cout << flush;
  int ans;
  cin >> ans;
  return (x1 <= tx1 && y1 <= ty1 && x2 >= tx2 && y2 >= ty2 ? ans - 1 : ans);
}
void solve() {
  int x1 = 1, x2 = n, y1 = 1, y2 = n;
  for (int i = maxlg - 1; i >= (int)(0); i--) {
    if (x1 + (1 << i) <= x2 && ask(x1 + (1 << i), y1, x2, y2)) x1 += (1 << i);
  }
  for (int i = maxlg - 1; i >= (int)(0); i--) {
    if (x2 - (1 << i) >= x1 && ask(x1, y1, x2 - (1 << i), y2)) x2 -= (1 << i);
  }
  for (int i = maxlg - 1; i >= (int)(0); i--) {
    if (y1 + (1 << i) <= y2 && ask(x1, y1 + (1 << i), x2, y2)) y1 += (1 << i);
  }
  for (int i = maxlg - 1; i >= (int)(0); i--) {
    if (y2 - (1 << i) >= y1 && ask(x1, y1, x2, y2 - (1 << i))) y2 -= (1 << i);
  }
  if (tx1) {
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
    cout << tx1 << " " << ty1 << " " << tx2 << " " << ty2 << endl;
  } else {
    tx1 = x1;
    tx2 = x2;
    ty1 = y1;
    ty2 = y2;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  solve();
  solve();
}
