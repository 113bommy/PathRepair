#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double x1, x2;
  cin >> x1 >> x2;
  vector<pair<double, double>> p;
  for (int i = 0; i < n; i++) {
    double k, b;
    cin >> k >> b;
    double y1 = k * x1 + b;
    double y2 = k * x2 + b;
    p.push_back(make_pair(y1, y2));
  }
  sort(p.begin(), p.end());
  double min = p[0].second;
  for (int i = 0; i < p.size() - 1; i++)
    if (p[i].second > p[i + 1].second) {
      cout << "YES";
      return 0;
    }
  cout << "NO";
  return 0;
}
