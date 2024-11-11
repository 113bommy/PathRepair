#include <bits/stdc++.h>
using namespace std;
int main() {
  setlocale(LC_ALL, "Russian");
  int n;
  int b;
  cin >> n >> b;
  vector<double> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  double sred = (sum + b) / n;
  bool yes = 1;
  for (int i = 0; i < n; i++) {
    a[i] = sred - a[i];
    if (a[i] < 0) yes = 0;
  }
  if (!yes)
    cout << -1;
  else {
    for (int i = 0; i < n; i++)
      cout << setprecision(6) << fixed << a[i] << endl;
  }
}
