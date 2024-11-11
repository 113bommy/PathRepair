#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
unsigned long long R, N, pos, sol, cnt;
double x, y, D[2100100];
unsigned long long C[2100100];
double th = 1.0 / 2;
double tb = cos(M_PI / 6);
double h = 2 * tb;
double w = 1 + 2 * th;
double dst() { return sqrt(((x) * (x)) + ((y) * (y))); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> R;
  N = 2 * R;
  for (unsigned long long I = 1; I <= N; I++) {
    x = 0.5;
    y = h * (I - 1) + h / 2;
    D[I] = dst() - EPS;
    C[I] = (C[I - 1] + I * 6 - 6 + (I == 1));
  }
  assert(D[N] > R);
  pos = upper_bound(D + 1, D + 1 + N, R) - D;
  sol += C[pos - 1];
  x = pos / 2 + ((pos + 1) / 2) * w - w / 2;
  if (pos % 2 == 0) x += w / 4;
  y = (pos / 2.0) * h;
  y = y - h / 2;
  y = y - h;
  if (y < EPS) y = 0;
  cnt = pos - 2;
  while (true) {
    while (y + EPS >= 0) {
      if (dst() - EPS <= R) {
        sol += 6 * cnt;
        break;
      }
      cnt -= 2;
      y -= h;
    }
    if (y < 0) break;
    x += 0.75 * w;
    y -= 0.5 * h;
    cnt--;
  }
  cout << sol << endl;
}
