#include <bits/stdc++.h>
using namespace std;
pair<long double, int> A[100005], B[100005];
long double ans = 0;
int main() {
  long long int ax, ay, bx, by, tx, ty, s, d, n;
  cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> d;
    ans += 2.0 * (sqrt((tx - s) * (tx - s) + (ty - d) * (ty - d)));
    A[i].first = sqrt(pow(ax - s, 2) + pow(ay - d, 2)) -
                 sqrt(pow(s - tx, 2) + pow(d - ty, 2));
    A[i].second = i;
    B[i].first = sqrt(pow(bx - s, 2) + pow(by - d, 2)) -
                 sqrt(pow(s - tx, 2) + pow(d - ty, 2));
    B[i].second = i;
  }
  sort(A, A + n);
  sort(B, B + n);
  long double temp = min(A[0].first, B[0].first);
  if (n > 1) {
    if (A[0].second == B[0].second) {
      temp = min(temp, min(A[0].first + B[1].first, A[1].first + B[0].first));
    } else
      temp = min(temp, A[0].first + B[0].first);
  }
  cout << fixed << setprecision(1) << ans + temp << endl;
  return 0;
}
