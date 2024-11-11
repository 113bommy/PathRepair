#include <bits/stdc++.h>
using namespace std;
double a[1123456];
int main() {
  int n, j;
  double w;
  cin >> n >> w;
  for (int i = 0; i < 2 * n; i++) {
    scanf("%d", &j);
    a[i] = j;
  }
  sort(a, a + 2 * n);
  w /= n;
  cout << fixed << 3 * n * min(a[0], min(a[n] / 2, w / 3));
  return 0;
}
