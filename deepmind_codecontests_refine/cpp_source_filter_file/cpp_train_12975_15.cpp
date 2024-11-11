#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, r;
long double x[N], y[N];
int main() {
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    long double my = r;
    for (int j = 0; j < i; j++) {
      if (abs(x[i] - x[j]) <= 2 * r) {
        auto sqr = [](long double x) { return x * x; };
        long double cy = y[j] + sqrt(sqr(2 * r) - sqrt(x[i] - x[j]));
        my = max(my, cy);
      }
    }
    y[i] = my;
    cout << setprecision(8) << fixed << y[i] << ' ';
  }
  cout << endl;
  return 0;
}
