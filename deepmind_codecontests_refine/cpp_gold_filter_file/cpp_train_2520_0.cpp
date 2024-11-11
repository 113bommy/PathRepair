#include <bits/stdc++.h>
using namespace std;
float dist(int n, int x[], int y[]) {
  float distance = 0;
  for (int i = 0; i < n - 1; i++) {
    distance += sqrt((x[i + 1] - x[i]) * (x[i + 1] - x[i]) +
                     (y[i + 1] - y[i]) * (y[i + 1] - y[i]));
  }
  return distance;
}
int main() {
  int n, k;
  cin >> n >> k;
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << fixed << setprecision(6) << dist(n, x, y) * k / 50;
}
