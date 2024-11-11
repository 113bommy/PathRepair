#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  vector<int> vec;
  for (int i = 0; i < 11; i++) {
    int d;
    cin >> d;
    vec.push_back(d);
  }
  for (int i = 10; i >= 0; i--) {
    int x = vec[i];
    double ans = pow(x, 3) * 5 + sqrt(abs(x));
    if (ans > 400) {
      printf("f(%d) = MAGNA NIMIS!\n", ans);
    } else {
      printf("f(%d) = %.2f\n", x, ans);
    }
  }
}
