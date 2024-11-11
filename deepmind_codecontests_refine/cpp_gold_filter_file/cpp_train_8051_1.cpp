#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int w = 0;
  double vtotal = 0, ototal = 0;
  vtotal = n * 100;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    ototal += k;
  }
  double p = ototal / vtotal;
  std::cout << p * 100;
  return 0;
}
