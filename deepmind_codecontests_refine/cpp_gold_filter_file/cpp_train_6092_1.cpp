#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
bool chmin(T1 &a, T2 b) {
  return b < a && (a = b, true);
}
template <class T1, class T2>
bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}
const long double pi = acos(-1.0l);
const int N = 1 << 19;
complex<long double> dr[N * 2];
long double angle[N * 2];
void update(int k, long double dl, long double da) {
  k += N - 1;
  long double rho = abs(dr[k]) + dl;
  long double theta = angle[k] + da;
  dr[k] = polar(rho, theta);
  angle[k] = theta;
  while (k > 0) {
    k = (k - 1) / 2;
    angle[k] = angle[k * 2 + 1] + angle[k * 2 + 2];
    dr[k] = dr[k * 2 + 1] + dr[k * 2 + 2] * polar(1.0l, angle[k * 2 + 1]);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (n); i++) update(i, 1, 0);
  for (int i = 0; i < (m); i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    y--;
    if (x == 1) {
      update(y, z, 0);
    } else {
      update(y, 0, -z / 180.0l * pi);
    }
    auto ans = dr[0];
    printf("%.20f %.20f\n", (double)real(ans), (double)imag(ans));
  }
  return 0;
}
