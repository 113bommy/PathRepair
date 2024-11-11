#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  long long Sum1 = x1 + y1;
  long long Sum2 = x2 + y2;
  long long Min1 = x1 - y1;
  long long Min2 = x2 - y2;
  if (Sum1 < 0 || Sum2 < 0) {
    long long minSum = min(Sum1, Sum2);
    minSum *= -1;
    Sum1 += (minSum + 2 * a) / (2 * a) * (2 * a);
    Sum2 += (minSum + 2 * a) / (2 * a) * (2 * a);
  }
  if (Min1 < 0 || Min2 < 0) {
    long long minMin = min(Min1, Min2);
    minMin *= -1;
    Min1 += (minMin + 2 * a) / (2 * a) * (2 * a);
    Min2 += (minMin + 2 * a) / (2 * a) * (2 * a);
  }
  long long X1 = Sum1 / (2 * a);
  long long X2 = Sum2 / (2 * a);
  long long Y1 = Min1 / (2 * b);
  long long Y2 = Min2 / (2 * b);
  long long ans = max(abs(X1 - X2), abs(Y1 - Y2));
  cout << ans << endl;
  return 0;
}
