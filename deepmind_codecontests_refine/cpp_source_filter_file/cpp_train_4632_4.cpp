#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  int s1 = n / 2;
  int s2 = n / 2 + 1;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    x -= a;
    if (a < y) {
      s1--;
    }
    s2--;
  }
  if (s2 < 0) {
    s1 += s2;
    s2 = 0;
  }
  if (s1 < 0) {
    cout << -1;
    return 0;
  }
  if (x - s1 - y * s2 < 0) {
    cout << -1;
    return 0;
  }
  while (s1 > 0) {
    s1--;
    printf("1 ");
  }
  while (s2 > 0) {
    s2--;
    printf("%d ", y);
  }
  return 0;
}
