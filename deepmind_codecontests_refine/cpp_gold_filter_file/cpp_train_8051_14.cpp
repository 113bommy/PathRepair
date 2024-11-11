#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x = x * 10;
    p[i] = x;
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += p[i];
  }
  double x = total * 100.00;
  int tol = n * 1000;
  double res = (x / tol);
  cout << res << endl;
}
