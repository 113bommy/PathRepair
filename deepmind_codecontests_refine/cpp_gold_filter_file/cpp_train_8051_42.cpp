#include <bits/stdc++.h>
using namespace std;
int main() {
  double n;
  cin >> n;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double a;
    cin >> a;
    double lala = a / 100;
    sum += lala;
  }
  cout << fixed << setprecision(9) << sum / n * 100;
}
