#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b;
  double sum = 0;
  double p = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    sum = sum + b;
  }
  p = sum / a;
  cout << fixed << setprecision(12) << p;
}
