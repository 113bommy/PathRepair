#include <bits/stdc++.h>
using namespace std;
struct city {
  int p;
  double d;
  city(int pp, double dd) : p(pp), d(dd) {}
};
struct my {
  bool operator()(city const &a, city const &b) { return a.d < b.d; }
} myobj;
int main() {
  int n;
  double s;
  cin >> n >> s;
  int i = 0;
  vector<int> x(n, 0);
  vector<int> y(n, 0);
  vector<city> a;
  while (i < n) {
    int t1;
    cin >> x[i] >> y[i] >> t1;
    double d = sqrt((x[i] * x[i]) + (y[i] * y[i]));
    a.push_back(city(t1, d));
    i++;
  }
  std::sort(a.begin(), a.end(), myobj);
  i = 0;
  int pop = s;
  while (i < a.size()) {
    pop += a[i].p;
    if (pop > 1000000) {
      cout.precision(9);
      cout << a[i - 1].d << endl;
      return 0;
    }
    i++;
  }
  cout << -1 << endl;
}
