#include <bits/stdc++.h>
using namespace std;
struct Car {
  int id, lo, hi;
  Car(){};
  Car(int id_, int lo_, int hi_) : id(id_), lo(lo_), hi(hi_){};
  bool operator<(const Car& other) const { return lo < other.lo; }
};
int L, b, f, n, x, y;
vector<Car> v;
int main() {
  cin >> L >> b >> f;
  cin >> n;
  for (int it = 1; it <= n; it++) {
    cin >> x >> y;
    if (x == 2) {
      for (int i = 0; i < v.size(); i++)
        if (v[i].id == y) {
          v.erase(v.begin() + i);
          break;
        }
    } else {
      if (v.empty()) {
        if (y + f <= L) {
          v.push_back(Car(it, 0, y));
          cout << 0 << endl;
        } else
          cout << -1 << endl;
      } else {
        if (v.front().lo >= f + y) {
          v.push_back(Car(it, 0, y));
          cout << 0 << endl;
          sort(v.begin(), v.end());
        } else {
          bool ok = false;
          for (int i = 1; i + 1 < v.size(); i++) {
            if (v[i - 1].hi + b + y + f <= v[i].lo) {
              ok = true,
              v.push_back(Car(it, v[i - 1].hi + b, v[i - 1].hi + b + y));
              break;
            }
          }
          if (not ok) {
            if (v.back().hi + b + y <= L)
              ok = true,
              v.push_back(Car(it, v.back().hi + b, v.back().hi + b + y));
          }
          if (ok)
            cout << v.back().lo << endl;
          else
            cout << -1 << endl;
          sort(v.begin(), v.end());
        }
      }
    }
  }
  return (0);
}
