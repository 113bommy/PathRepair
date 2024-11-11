#include <bits/stdc++.h>
using namespace std;
vector<pair<double, pair<double, double> > > v;
int n;
double a, b, p;
bool sepuede(double se) {
  vector<double> aux;
  for (int i = 0; i < n; i++) {
    aux.push_back(v[i].second.second - (se * v[i].second.first));
  }
  double falta = 0.0;
  for (int i = 0; i < n; i++) {
    if (aux[i] < 0.0) {
      falta += (-aux[i]);
    }
  }
  return falta <= se * p;
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(
        pair<double, pair<double, double> >(0, pair<double, double>(a, b)));
  }
  double ini = 0.0, fin = 100000000000000;
  for (int i = 0; i < 100; i++) {
    double m = (ini + fin) / 2.0;
    if (sepuede(m)) {
      ini = m;
    } else {
      fin = m;
    }
  }
  if (ini > 1000000000000)
    cout << "-1\n";
  else
    cout << ini << "\n";
  return 0;
}
