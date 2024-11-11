#include <bits/stdc++.h>
using namespace std;
double n, h;
int main() {
  cin >> n >> h;
  double k = (1.0 / 2.0 * 1 * h) / n;
  for (int i = 1; i <= n - 1; i++) {
    printf("\n%.81f", sqrt(k * i * 4));
  }
}
