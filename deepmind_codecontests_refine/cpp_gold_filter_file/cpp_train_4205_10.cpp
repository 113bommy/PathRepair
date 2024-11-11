#include <bits/stdc++.h>
using namespace std;
template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()) {
  v.assign(a, vector<T>(b, t));
}
int main() {
  double pi = acos(-1.0);
  int m, n;
  cin >> n >> m;
  vector<complex<double> > v(2 * m);
  double r = 1e8 - 3.0;
  double t = 2.0 * pi / m;
  double d = 1e-6;
  for (int i = 0; i < m; ++i) {
    v[i] = polar(r, t * i);
    v[i + m] = polar(r - 1e6, t * i + d);
  }
  v.resize(n);
  if (m == 3 && n >= 5) {
    puts("-1");
  } else {
    for (int i = 0; i < n; ++i) {
      printf("%d %d\n", (int)real(v[i]), (int)imag(v[i]));
    }
  }
}
