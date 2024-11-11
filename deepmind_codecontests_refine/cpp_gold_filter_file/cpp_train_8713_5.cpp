#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 7;
const int INF = (int)1e9 + 7;
const double eps = 1e-9;
const double pi = 3.141592653;
double k, n, m, d[maxn], mn = INF, mn2 = INF, mn3 = INF, mx = -INF, mn4 = INF,
                         cnt;
double x[5], y[5], x2, y2;
string s;
map<string, bool> mp;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    mp[s] = 1;
  }
  cout << 6 - n << endl;
  if (n == 6) {
    return 0;
  }
  if (!mp["red"]) {
    cout << "Reality" << endl;
  }
  if (!mp["purple"]) {
    cout << "Power" << endl;
  }
  if (!mp["green"]) {
    cout << "Time" << endl;
  }
  if (!mp["orange"]) {
    cout << "Soul" << endl;
  }
  if (!mp["blue"]) {
    cout << "Space" << endl;
  }
  if (!mp["yellow"]) {
    cout << "Mind" << endl;
  }
  return 0;
}
