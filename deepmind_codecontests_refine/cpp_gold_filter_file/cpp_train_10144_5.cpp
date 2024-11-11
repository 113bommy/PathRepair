#include <bits/stdc++.h>
using namespace std;
template <class T>
string ToString(T t) {
  stringstream s;
  s << t;
  return s.str();
}
template <class T>
void ToOther(T& t, string a) {
  stringstream s(a);
  s >> t;
}
int n, m, T;
int A, B, C;
int a[305][305];
int base[305];
map<int, int> h[305];
int calc(int s, int e) {
  if (s == e) return A;
  if (s > e) return C;
  return B;
}
int r = (1 << 30);
int sx, sy, ex, ey;
void checkmin(int need, int bb, map<int, int>& mm, int s, int e, int down) {
  map<int, int>::iterator it;
  it = mm.lower_bound(need);
  if (it != mm.begin()) it--;
  if (it != mm.begin()) it--;
  for (int i = 0; i < 5; i++, it++) {
    if (it == mm.end()) break;
    int val = it->first;
    int len = it->second;
    if (((val - need) < 0 ? (-(val - need)) : (val - need)) < r) {
      r = ((val - need) < 0 ? (-(val - need)) : (val - need));
      sx = s;
      ex = e;
      sy = len;
      ey = down;
    }
  }
}
int main() {
  cin >> n >> m >> T;
  cin >> A >> B >> C;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int s = 0; s < m; s++) {
    memset(base, 0, sizeof(base));
    for (int i = 0; i <= 300; i++) h[i].clear();
    for (int i = 2; i < n; i++) {
      int ii = i - 2;
      int up = 0;
      int down = 0;
      up += calc(a[ii][s], a[ii][s + 1]);
      for (int e = s + 2; e < m; e++) {
        up += calc(a[ii][e - 1], a[ii][e]);
        if (ii >= 1) {
          base[e] += calc(a[ii][s], a[ii - 1][s]);
          base[e] += calc(a[ii - 1][e], a[ii][e]);
        }
        h[e][up - base[e]] = ii;
      }
      down += calc(a[i][s + 1], a[i][s]);
      for (int e = s + 2; e < m; e++) {
        down += calc(a[i][e], a[i][e - 1]);
        int temp2 = calc(a[i][s], a[i - 1][s]) + calc(a[i - 1][s], a[i - 2][s]);
        temp2 += calc(a[i - 2][e], a[i - 1][e]) + calc(a[i - 1][e], a[i][e]);
        int need = T - down - base[e] - temp2;
        checkmin(need, base[e], h[e], s, e, i);
      }
    }
  }
  sy++;
  sx++;
  ey++;
  ex++;
  printf("%d %d %d %d\n", sy, sx, ey, ex);
}
