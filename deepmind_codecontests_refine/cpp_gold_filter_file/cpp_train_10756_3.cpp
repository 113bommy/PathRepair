#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void smax(T &a, T b) {
  if (a < b) a = b;
}
const int lose = -1e9 - 2532357;
const int draw = -1e9 - 5343624;
int solve(int x, int a, int b) {
  if (a <= x && x <= b) return x;
  int sgn = 1;
  if (x < 0) {
    swap(a, b);
    a = -a, b = -b, x = -x;
    sgn = -1;
  }
  if (x < a) return draw;
  if (a <= 0) return draw;
  int sum = a + b;
  if (x % sum == 0) return a > 0 ? lose : draw;
  long long r = x % sum, l = sum - r;
  if (a <= r && r <= b) return sgn * r;
  if (a <= -l && -l <= b) return sgn * (-l);
  assert(0 < a);
  int mv = x - (x - a) / sum * sum;
  if (mv <= b) return sgn * mv;
  return draw;
}
int main() {
  ios_base::sync_with_stdio(false);
  int x1, x2, x;
  int a, b;
  cin >> x1 >> x2 >> a >> b;
  x = x2 - x1;
  int p = solve(x, a, b);
  if (p == lose)
    cout << "SECOND" << endl;
  else if (p == draw)
    cout << "DRAW" << endl;
  else
    cout << "FIRST" << endl << x1 + p << endl;
  {
    int _;
    cin >> _;
    return 0;
  }
}
