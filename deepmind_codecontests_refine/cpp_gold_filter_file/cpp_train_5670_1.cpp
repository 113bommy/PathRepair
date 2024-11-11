#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
int main() {
  istream &fin = cin;
  int L, b, f;
  fin >> L >> b >> f;
  int n;
  fin >> n;
  set<vector<int> > cars;
  vector<int> car(3);
  car[0] = -b;
  car[1] = -b;
  car[2] = -1;
  cars.insert(car);
  car[0] = L + f;
  car[1] = L + f;
  car[2] = -1;
  cars.insert(car);
  int reqcnt = 0;
  for (int i = 0; i < n; i++) {
    int r, v;
    fin >> r >> v;
    if (r == 1) {
      reqcnt++;
      int tb = (*cars.begin())[1];
      int tf;
      bool ok = false;
      for (set<vector<int> >::iterator svi = cars.begin(); svi != cars.end();
           svi++) {
        if (svi == cars.begin()) continue;
        car = *svi;
        tf = car[0];
        if (tf - tb >= v + b + f) {
          car[0] = tb + b;
          car[1] = tb + b + v;
          car[2] = i + 1;
          cars.insert(car);
          ok = true;
          cout << tb + b << endl;
          break;
        }
        tb = car[1];
      }
      if (!ok) cout << -1 << endl;
    } else {
      for (set<vector<int> >::iterator svi = cars.begin(); svi != cars.end();
           svi++) {
        car = *svi;
        if (car[2] == v) {
          cars.erase(svi);
          break;
        }
      }
    }
  }
}
