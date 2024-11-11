#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > friends(60005);
int n;
double res(double x) {
  double l = 0, r = 1e9;
  for (int i = 0; i < n; i++) {
    l = max(l, friends[i].first - x * friends[i].second);
    r = min(r, friends[i].first + x * friends[i].second);
  }
  if (l > r) {
    return false;
  }
  return true;
}
double calc_t() {
  double l = 0, r = 1e6, m;
  while (r - l > 1e-6) {
    m = l + ((r - l) / 2);
    double aux = res(m);
    if (aux) {
      r = m;
    } else {
      l = m;
    }
  }
  return m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> friends[i].first;
  }
  for (int i = 0; i < n; i++) {
    cin >> friends[i].second;
  }
  cout << setprecision(12) << calc_t() << endl;
  return 0;
}
