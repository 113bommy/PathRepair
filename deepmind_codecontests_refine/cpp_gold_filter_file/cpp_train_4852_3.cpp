#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, d;
  cin >> n >> d;
  double angle = (n - 2) * 180 / n;
  cout << 2 << " " << 1 << " ";
  double current_angle = angle / (n - 2);
  double min_abs = 1e9;
  int vertex = 3;
  for (int i = 3; i <= n; i++) {
    if (abs(current_angle - d) < min_abs) {
      min_abs = abs(current_angle - d);
      vertex = i;
    }
    current_angle += angle / (n - 2);
  }
  cout << vertex << endl;
}
