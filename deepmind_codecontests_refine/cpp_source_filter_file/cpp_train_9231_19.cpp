#include <bits/stdc++.h>
using namespace std;
double x, y;
double dist(double a, double b) {
  double c = (x - a) * (x - a) + (y - b) * (y - b);
  return sqrt(c);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, vb, vs;
  cin >> n >> vb >> vs;
  double a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> x >> y;
  double mm = (double)1e9;
  int id;
  for (int i = 1; i < n; i++) {
    if (mm > (double)a[i] * vs + (double)vb * dist(a[i], 0)) {
      mm = (double)a[i] * vs + (double)vb * dist(a[i], 0);
      id = i;
    }
  }
  cout << id + 1;
  return 0;
}
