#include <bits/stdc++.h>
using namespace std;
int main() {
  float n, p;
  cin >> n;
  float sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> p;
    sum += p;
  }
  float ans;
  ans = (float)(sum / n);
  std::cout << std::setprecision(7) << ans << '\n';
  return 0;
}
