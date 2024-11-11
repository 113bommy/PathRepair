#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, a[100000], b[100000], g = 0, sum1 = 0, sum = 0, t = 0;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    t += b[i];
    int w = c * t;
    int r = a[i] - w;
    if (r > 0) {
      sum += r;
    }
  }
  for (int j = n - 1; j >= 0; j--) {
    g += b[j];
    int b = c * g;
    int y = a[j] - b;
    if (y > 0) {
      sum1 += y;
    }
  }
  if (sum == sum1) cout << "Tie" << endl;
  if (sum > sum1) {
    cout << "Limak" << endl;
  }
  if (sum1 > sum) {
    cout << "Radewoosh" << endl;
  }
  return 0;
}
