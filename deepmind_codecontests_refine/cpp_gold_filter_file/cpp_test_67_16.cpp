#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  double p;
  cin >> n >> p;
  for (int i = n; i >= 0; i--) {
    double pp = 0.0;
    double p0 = n * (n - 1) * (n - 2);
    double p1 = (n - i) * (n - i - 1) * (n - i - 2);
    if (p1 > 0) pp += p1 / p0;
    double p2 = (n - i) * (n - i - 1) * i * 3;
    if (p2 > 0) pp += p2 / p0;
    double p3 = (n - i) * i * (i - 1) * 3;
    if (p3 > 0) pp += p3 / p0 / 2;
    if (pp >= p) {
      cout << n - i << endl;
      break;
    }
  }
  return 0;
}
