#include <bits/stdc++.h>
using namespace std;
void solve() {
  long double x, y, z;
  cin >> x >> y >> z;
  vector<pair<long double, string> > res;
  if (max(max(x, y), z) > 1.0001) {
    if (x > 1.0001) {
      res.push_back({log(log(x)) + log(y) * z, "x^y^z"});
    }
    if (x > 1.0001) {
      res.push_back({log(log(x)) + log(z) * y, "x^z^y"});
    }
    if (x > 1.0001) {
      res.push_back({log(log(x)) + log(z * y), "(x^y)^z"});
    }
    if (y > 1.0001) {
      res.push_back({log(log(y)) + log(x) * z, "y^x^z"});
    }
    if (y > 1.0001) {
      res.push_back({log(log(y)) + log(z) * x, "y^z^x"});
    }
    if (y > 1.0001) {
      res.push_back({log(log(y)) + log(z * x), "(y^x)^z"});
    }
    if (z > 1.0001) {
      res.push_back({log(log(z)) + log(x) * y, "z^x^y"});
    }
    if (z > 1.0001) {
      res.push_back({log(log(z)) + log(y) * x, "z^y^x"});
    }
    if (z > 1.0001) {
      res.push_back({log(log(z)) + log(y * x), "(z^x)^y"});
    }
  } else {
    res.push_back({pow(x, pow(y, z)), "x^y^z"});
    res.push_back({pow(x, pow(z, y)), "x^z^y"});
    res.push_back({pow(x, y * z), "(x^y)^z"});
    res.push_back({pow(y, pow(x, z)), "y^x^z"});
    res.push_back({pow(y, pow(z, x)), "y^z^x"});
    res.push_back({pow(y, x * z), "(y^x)^z"});
    res.push_back({pow(z, pow(y, x)), "z^y^x"});
    res.push_back({pow(z, pow(x, y)), "z^x^y"});
    res.push_back({pow(z, y * x), "(z^y)^x"});
  }
  stable_sort(res.begin(), res.end(),
              [](pair<long double, string> t1, pair<long double, string> t2) {
                return t1.first > t2.first;
              });
  cout << res[0].second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios_base::fixed);
  cout.precision(28);
  solve();
  return 0;
}
