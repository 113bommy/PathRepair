#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const double EPS = 1e-10;
int a[MAXN], b[MAXN];
int n, p;
bool f(double T) {
  double have = 0;
  for (int i = 0; i < n; ++i) {
    double curr = a[i] * T;
    if (curr > b[i] + EPS) have += curr - b[i];
  }
  return have + EPS <= p * T;
}
int main() {
  cin >> n >> p;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    sum += a[i];
  }
  if (sum <= p) {
    cout << -1;
    return 0;
  }
  double left = 0, right = 1e10;
  for (int i = 0; i < 100; ++i) {
    double middle = (left + right) / 2.0;
    if (f(middle))
      left = middle;
    else
      right = middle;
  }
  cout << fixed;
  cout.precision(10);
  cout << left;
  return 0;
}
