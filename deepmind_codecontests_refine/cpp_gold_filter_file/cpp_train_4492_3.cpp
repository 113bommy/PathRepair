#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-9);
int dcmp(double x, double y) { return fabs(x - y) <= eps ? 0 : x > y ? -1 : 1; }
int main() {
  ios_base::sync_with_stdio(false);
  long long n, x, y;
  cin >> n >> x >> y;
  long long sumX = n - 1, sumY = n - 1;
  long long last = y - n + 1;
  sumX = sumX + last * last;
  sumY = sumY + last;
  if (sumX >= x && sumY <= y && last > 0) {
    for (int i = 0; i < n - 1; ++i) {
      cout << 1 << endl;
    }
    cout << last << endl;
  } else
    cout << -1 << endl;
  return 0;
}
