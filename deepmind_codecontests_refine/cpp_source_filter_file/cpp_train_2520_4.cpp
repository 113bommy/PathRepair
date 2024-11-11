#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100 + 10;
float x[MaxN], y[MaxN];
int main() {
  float n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  float sum = 0;
  for (int i = 1; i < n; ++i) {
    float dx = x[i] - x[i - 1];
    float dy = y[i] - y[i - 1];
    sum += sqrt(dx * dx + dy * dy);
  }
  cout << setprecision(6) << sum * k / 50;
}
