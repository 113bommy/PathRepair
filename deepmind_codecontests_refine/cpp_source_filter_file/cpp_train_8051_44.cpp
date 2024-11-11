#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  double x = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    x += t / 100.0;
  }
  printf("%.9lf\n", x / n);
}
