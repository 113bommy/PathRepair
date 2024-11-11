#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<double> a;
  int x0, y0;
  int n;
  cin >> n >> x0 >> y0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    double m;
    sort(((a).begin()), ((a).end()));
    if (x - x0 != 0) {
      m = (y - y0) / (x - x0);
    } else {
      m = 1000;
    }
    if (a.empty()) {
      a.push_back(m);
    } else {
      if (binary_search(((a).begin()), ((a).end()), m) == false) {
        a.push_back(m);
      }
    }
  }
  cout << a.size();
  return 0;
}
