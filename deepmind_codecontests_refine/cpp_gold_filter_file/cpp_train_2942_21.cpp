#include <bits/stdc++.h>
int main() {
  using namespace std;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    double n;
    cin >> n;
    n /= 2;
    printf("%.0f\n", ceil(n));
  }
  return 0;
}
