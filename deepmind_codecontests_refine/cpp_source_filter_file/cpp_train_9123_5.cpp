#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
int n, m, c;
double w, v, d;
vector<double> a, b;
struct ml {
  int n;
  double z;
  ml(int nn = 0, double zz = 0.0) {
    n = nn;
    z = zz;
  }
};
vector<ml> e0(0);
vector<vector<ml> > e;
int main() {
  cout.setf(ios::fixed);
  cout.precision(7);
  cin >> n >> w >> m;
  v = w * n / m;
  if (2 * n < m)
    cout << "NO";
  else {
    e.assign(m, e0);
    a.assign(n, w);
    b.assign(m, v);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2 && a[i] > eps; j++) {
        d = min(a[i], b[c]);
        a[i] -= d;
        b[c] -= d;
        e[c].push_back(ml(i + 1, d));
        if (b[c] < eps) c++;
      }
      if (a[i] > eps) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES"
         << "\n";
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < e[i].size(); j++)
        cout << e[i][j].n << " " << e[i][j].z << " ";
      cout << "\n";
    }
  }
  return 0;
}
