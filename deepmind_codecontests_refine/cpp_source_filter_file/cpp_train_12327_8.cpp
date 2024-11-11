#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int trace = 0, temp;
  double x = 0;
  for (int i = 1; i < n; i++)
    if (a[i] <= a[i - 1]) trace = 1;
  cout << setprecision(6);
  if (trace == 1) {
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
          x++;
        }
      }
    if (int(x) & 1)
      printf("%.6lf\n", 2 * x - 1);
    else
      printf("%.6lf\n", 2 * x + 1);
  } else {
    printf("%.6lf\n", 0);
  }
  return 0;
}
