#include <bits/stdc++.h>
using namespace std;
long double eps = 0.0000001;
struct Mn {
  long double num;
  vector<long double> v;
};
Mn del(Mn a, Mn b) {
  long double diff = a.num - b.num + 1;
  for (long double i = 0; i < diff; i++) {
    long double degree = a.num - i;
    long double raz = degree - b.num;
    long double st = a.v[degree] / b.v[b.num];
    for (long double j = 0; j <= b.num; j++) {
      long double now = j + raz;
      long double coeff = st * b.v[j];
      a.v[now] -= coeff;
    }
  }
  long double old = a.num;
  for (long double i = a.num; i >= 0; i--) {
    if (abs(a.v[i]) > eps) {
      a.num = i;
      break;
    }
  }
  if (a.num == old) a.num = 0;
  return a;
}
long double gcd(Mn a, Mn b) {
  if (b.num == 0 && abs(b.v[0]) < eps) return 0;
  Mn res = del(a, b);
  return gcd(b, res) + 1;
}
signed main() {
  long double n;
  cin >> n;
  srand(time(NULL));
  while (true) {
    Mn f, s;
    f.num = -1;
    s.num = -1;
    vector<long double> a, b;
    for (long double i = 0; i < n; i++) {
      long double X = rand() % 2;
      long double Y = rand() % 2;
      if (X == 0) a.push_back(1);
      if (X == 1) a.push_back(-1);
      if (X == 2) a.push_back(0);
      if (i != n - 1) {
        if (Y == 0) b.push_back(1);
        if (Y == 1) b.push_back(-1);
        if (Y == 2) b.push_back(0);
      }
    }
    a.push_back(1);
    b.push_back(1);
    f.v = a;
    s.v = b;
    for (long double i = n; i >= 0; i--) {
      if (f.v[i] != 0) {
        f.num = i;
        break;
      }
    }
    for (long double i = n - 1; i >= 0; i--) {
      if (s.v[i] != 0) {
        s.num = i;
        break;
      }
    }
    Mn f1 = f, s1 = s;
    long double g = gcd(f, s);
    if (g == n) {
      cout << f1.num << endl;
      for (long double i = 0; i <= f1.num; i++) cout << f1.v[i] << " ";
      cout << endl;
      cout << s1.num << endl;
      for (long double i = 0; i <= s1.num; i++) cout << s1.v[i] << " ";
      cout << endl;
      return 0;
    }
  }
  return 0;
}
