#include <bits/stdc++.h>
const int inf = 1e9 + 5;
const long long linf = 5e18 + 5;
const long double eps = 1e-7;
const int dd = 2e5 + 7;
const int maxn = 2e3 + 10;
const long long mod = 1e9 + 7;
using namespace std;
long double fun(vector<long double> qwe, int k) {
  long double x = qwe[0];
  long double y = qwe[1];
  long double z = qwe[2];
  long double ans = 0;
  if (k == 0) {
    ans = log(x) * pow(y, z);
  }
  if (k == 1) {
    ans = log(x) * pow(z, y);
  }
  if (k == 2) {
    ans = log(x) * y * z;
  }
  if (k == 3) {
    ans = log(x) * y * z;
  }
  if (k == 4) {
    ans = log(y) * pow(x, z);
  }
  if (k == 5) {
    ans = log(y) * pow(z, x);
  }
  if (k == 6) {
    ans = log(y) * x * z;
  }
  if (k == 7) {
    ans = log(y) * x * z;
  }
  if (k == 8) {
    ans = log(z) * pow(x, y);
  }
  if (k == 9) {
    ans = log(z) * pow(y, x);
  }
  if (k == 10) {
    ans = log(z) * x * y;
  }
  if (k == 11) {
    ans = log(z) * x * y;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
    if (!01) {
      freopen(
          "sufpref"
          ".in",
          "r", stdin);
      freopen(
          "sufpref"
          ".out",
          "w", stdout);
    }
  }
  vector<pair<long double, string> > qwe(3);
  cin >> qwe[0].first >> qwe[1].first >> qwe[2].first;
  qwe[0].second = "x";
  qwe[1].second = "y";
  qwe[2].second = "z";
  vector<long double> zxc;
  zxc.push_back(qwe[0].first);
  zxc.push_back(qwe[1].first);
  zxc.push_back(qwe[2].first);
  long double maxx = 0;
  int ind = 0;
  for (long long i = 0; i < 12; ++i) {
    if (maxx < fun(zxc, i)) maxx = fun(zxc, i), ind = i;
  }
  map<int, string> asd;
  asd[0] = qwe[0].second + "^" + qwe[1].second + "^" + qwe[2].second;
  asd[1] = qwe[0].second + "^" + qwe[2].second + "^" + qwe[1].second;
  asd[2] =
      "(" + qwe[0].second + "^" + qwe[1].second + ")" + "^" + qwe[2].second;
  asd[3] =
      "(" + qwe[0].second + "^" + qwe[2].second + ")" + "^" + qwe[1].second;
  asd[4] = qwe[1].second + "^" + qwe[0].second + "^" + qwe[2].second;
  asd[5] = qwe[1].second + "^" + qwe[2].second + "^" + qwe[0].second;
  asd[6] =
      "(" + qwe[1].second + "^" + qwe[0].second + ")" + "^" + qwe[2].second;
  asd[7] =
      "(" + qwe[1].second + "^" + qwe[2].second + ")" + "^" + qwe[0].second;
  asd[8] = qwe[2].second + "^" + qwe[0].second + "^" + qwe[1].second;
  asd[9] = qwe[2].second + "^" + qwe[1].second + "^" + qwe[0].second;
  asd[10] =
      "(" + qwe[2].second + "^" + qwe[0].second + ")" + "^" + qwe[1].second;
  asd[11] =
      "(" + qwe[2].second + "^" + qwe[1].second + ")" + "^" + qwe[0].second;
  cout << asd[ind];
  return 0;
}
