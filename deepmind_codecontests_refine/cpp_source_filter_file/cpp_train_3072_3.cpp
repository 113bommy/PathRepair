#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double x1, x2;
  cin >> x1 >> x2;
  x1 = x1 + 0.000001;
  x2 = x2 - 0.000001;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  vector<pair<double, double> > y1(n);
  for (int i = 0; i < n; i++) {
    y1[i].second = i;
    y1[i].first = (double)v[i].first * x1 + (double)v[i].second;
  }
  sort(y1.begin(), y1.end());
  vector<pair<double, double> > y2(n);
  for (int i = 0; i < n; i++) {
    y2[i].second = i;
    y2[i].first = (double)v[i].first * x2 + (double)v[i].second;
  }
  sort(y2.begin(), y2.end());
  for (int i = 0; i < n; i++) {
    if (y1[i].second != y2[i].second) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
