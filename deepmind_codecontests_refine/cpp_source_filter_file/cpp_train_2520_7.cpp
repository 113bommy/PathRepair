#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
long double sum;
int x, y, n;
double k, s = 50.000;
int a[N];
int b[N];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < n - 1; i++) {
    sum += sqrt(((a[i] - a[i + 1]) * (a[i] - a[i + 1])) +
                ((b[i] - b[i + 1]) * (b[i] - b[i + 1])));
  }
  double sum2;
  sum2 = (sum / s) * k;
  printf("%.5lf", sum2);
  return 0;
}
