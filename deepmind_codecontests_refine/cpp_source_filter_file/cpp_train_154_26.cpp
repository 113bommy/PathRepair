#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long double EPS = 1e-6;
bool cmp(const pair<pair<long double, string>, int> &a,
         const pair<pair<long double, string>, int> &b) {
  if (a.first.first >= 0) {
    if (b.first.first < 0) {
      return false;
    }
    if (abs(a.first.first - b.first.first) > EPS) {
      return a.first.first < b.first.first;
    }
    return a.second > b.second;
  }
  if (abs(a.first.first - b.first.first) > EPS) {
    return a.first.first > b.first.first;
  }
  return a.second > b.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long double x, y, z;
  cin >> x >> y >> z;
  vector<pair<pair<long double, string>, int> > all;
  all.push_back(make_pair(make_pair(powl(y, z) * log(x), "x^y^z"), 0));
  all.push_back(make_pair(make_pair(powl(z, y) * log(x), "x^z^y"), 1));
  all.push_back(make_pair(make_pair(y * z * log(x), "(x^y)^z"), 2));
  all.push_back(make_pair(make_pair(powl(x, z) * log(y), "y^x^z"), 3));
  all.push_back(make_pair(make_pair(powl(z, x) * log(y), "y^z^x"), 4));
  all.push_back(make_pair(make_pair(z * x * log(y), "(y^x)^z"), 5));
  all.push_back(make_pair(make_pair(powl(x, y) * log(z), "z^x^y"), 6));
  all.push_back(make_pair(make_pair(powl(y, x) * log(z), "z^y^x"), 7));
  all.push_back(make_pair(make_pair(x * y * log(z), "(y^z)^x"), 8));
  sort(all.begin(), all.end(), cmp);
  cout << all.back().first.second << endl;
  return 0;
}
