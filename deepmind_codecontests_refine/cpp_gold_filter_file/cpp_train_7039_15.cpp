#include <bits/stdc++.h>
using namespace std;
long long cal(long long a, long long b, long long nine) {
  long long four = nine / 2;
  if (b < four) {
    return b * (nine - b);
  } else if (a > four + 1) {
    return a * (nine - a);
  } else {
    return four * (four + 1);
  }
}
int main() {
  long long A, B;
  long long ans = 0;
  cin >> A >> B;
  if (B < 10) ans = cal(A, B, 9);
  for (long long d = 10; d <= B; d *= 10) {
    if ((d - 1) >= A) {
      long long r = cal(A, d - 1, d - 1);
      ans = max(ans, r);
      A = d;
    }
    if (10 * d > B) {
      long long r = cal(A, B, 10 * d - 1);
      ans = max(ans, r);
    }
  }
  cout << ans << endl;
  return 0;
}
