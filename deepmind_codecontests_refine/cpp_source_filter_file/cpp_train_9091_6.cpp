#include <bits/stdc++.h>
using namespace std;
void TxtRead() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
const int N = 1e5 + 5;
const long long MOD = 1e8;
int main() {
  ios_base::sync_with_stdio(false);
  long double x1, y1, x2, y2, r1, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  if (r1 > r2) {
    swap(x1, x2);
    swap(y1, y2);
    swap(r1, r2);
  }
  long double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  cout << fixed << setprecision(6);
  if (d + r1 <= r2) {
    cout << r2 - d - r1;
  } else
    cout << max((long double)0, (d - r1 - r2) / 2.0) << "\n";
}
