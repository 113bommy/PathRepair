#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  int xs[n], ys[m];
  for (auto &x : xs) {
    cin >> x;
  }
  for (auto &y : ys) {
    cin >> y;
  }
  int l = *max_element(xs, xs + n);
  int r = *min_element(ys, ys + m);
  cout << (l < r && X <= l && r <= Y) ? "No War" : "War") << endl;
  return 0;
}