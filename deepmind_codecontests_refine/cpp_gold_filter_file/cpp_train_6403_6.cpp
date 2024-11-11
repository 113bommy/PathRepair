#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0);
const double epi = 1e-6;
const int N = 1e5 + 5;
long long x, y;
int main() {
  int i, j, n;
  cin >> n;
  vector<pair<long double, int> > v;
  long double t;
  for (i = 1; i <= n; ++i) {
    cin >> x >> y;
    t = atan2(y, x) * 180.0 / pi;
    if (t < 0) t += 360;
    v.push_back(make_pair(t, i));
  }
  sort(v.begin(), v.end());
  v.push_back(make_pair(v[0].first + 360, v[0].second));
  long double mini = 1e9 + 10, temp;
  int a, b;
  for (i = 0; i < n; ++i) {
    temp = v[i + 1].first - v[i].first;
    if (temp < mini) a = v[i + 1].second, b = v[i].second, mini = temp;
  }
  cout << b << " " << a << endl;
}
