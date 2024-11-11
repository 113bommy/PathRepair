#include <bits/stdc++.h>
using namespace std;
int n, w, m;
double a[100];
int kol[100];
vector<pair<int, double> > v[100];
int main() {
  cin >> n >> w >> m;
  double q = n * w * 1.0 / m;
  memset(kol, 0, sizeof(kol));
  for (int i = 0; i < 100; ++i) a[i] = w;
  for (int i = 0; i < m; ++i) {
    double p = q;
    int z = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] > 1e-9) {
        double temp = min(p, a[j]);
        v[i].push_back(make_pair(j + 1, temp));
        p -= temp;
        a[j] -= temp;
        ++z;
        ++kol[j];
        if (kol[j] > 2) {
          cout << "NO\n";
          return 0;
        }
        if (p < 1e-9) break;
      }
    }
    if (z == 0 || p > 1e-9) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      if (j) cout << " ";
      cout << v[i][j].first << " " << fixed << setprecision(10)
           << v[i][j].second;
    }
    cout << endl;
  }
  return 0;
}
