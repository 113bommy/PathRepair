#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Lagrange_Interpolation {
  long long dimension;
  vector<pair<T, T>> XY;
  vector<T> coefficient;
  Lagrange_Interpolation() {}
  Lagrange_Interpolation(vector<pair<T, T>>& xy) { initialization(xy); }
  ~Lagrange_Interpolation() {}
  inline T interpolation(T x) {
    T res = 0;
    for (int i = 0; i <= dimension; i++) {
      T temp = 1;
      for (int j = 0; j <= dimension; j++) {
        if (i == j) continue;
        temp = temp * (x - XY[j].first + ((int)1e6 + 3)) % ((int)1e6 + 3);
      }
      res = (res + temp * XY[i].second % ((int)1e6 + 3) * coefficient[i]) %
            ((int)1e6 + 3);
    }
    return res;
  }
  void exgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
  }
  void initialization(vector<pair<T, T>>& xy) {
    dimension = xy.size() - 1;
    XY = xy;
    coefficient.resize(dimension + 1);
    for (int i = 0; i <= dimension; i++) {
      T temp = 1;
      for (int j = 0; j <= dimension; j++) {
        if (i == j) continue;
        temp *= (xy[i].first - xy[j].first + ((int)1e6 + 3)) % ((int)1e6 + 3);
        temp %= ((int)1e6 + 3);
      }
      long long x, y;
      exgcd(temp, ((int)1e6 + 3), x, y);
      coefficient[i] = x;
    }
  }
};
int main() {
  Lagrange_Interpolation<long long> li;
  vector<pair<long long, long long>> test;
  for (long long i = 0, num; i <= 10; i++) {
    cout << "? " << i << endl;
    cout.flush();
    cin >> num;
    if (num == 0) {
      cout << "! " << i << endl;
      cout.flush();
      return 0;
    } else
      test.push_back(make_pair(i, num));
  }
  li.initialization(test);
  for (int i = 0; i < ((int)1e6 + 3); i++) {
    if (li.interpolation(i) == 0) {
      cout << "! " << i << endl;
      cout.flush();
      return 0;
    }
  }
  cout << "! " << -1 << endl;
  cout.flush();
  return 0;
}
