#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
double zero(double d) { return d < EPS ? 0.0 : d; }
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << '(' << p.first << ',' << p.second << ')';
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
  os << '[';
  for (int i = 0; i < (int)(a.size()); i++) os << (i ? " " : "") << a[i];
  return os << ']';
}
int main() {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(8);
  ios_base::sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  const int MLEN = 130;
  const int Z = MLEN / 2;
  int ant[2][MLEN][MLEN];
  int s = 0, d = 1;
  ant[s][Z][Z] = n;
  while (true) {
    bool update = false;
    memset(ant[d], 0, sizeof(ant[d]));
    for (int x = 0; x < (int)(MLEN); x++) {
      for (int y = 0; y < (int)(MLEN); y++) {
        if (ant[s][y][x] >= 4) {
          update = true;
          int add = ant[s][y][x] / 4;
          int r = ant[s][y][x] % 4;
          ant[d][y][x + 1] += add;
          ant[d][y][x - 1] += add;
          ant[d][y + 1][x] += add;
          ant[d][y - 1][x] += add;
          ant[d][y][x] = r;
        } else
          ant[d][y][x] += ant[s][y][x];
      }
    }
    if (!update) break;
    swap(s, d);
  }
  for (int i = 0; i < (int)(t); i++) {
    int x, y;
    cin >> x >> y;
    if (abs(x) < MLEN && abs(y) < MLEN)
      cout << ant[s][y + Z][x + Z] << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
