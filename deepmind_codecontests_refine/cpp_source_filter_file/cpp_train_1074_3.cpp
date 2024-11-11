#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n, a[1000] = {0};
  cin >> n;
  double res = 0, temp = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i += 2) {
    res += (a[i] * a[i] - a[i + 1] * a[i + 1]);
  }
  printf("%.10f", res * 3.1415926535);
  return 0;
}
