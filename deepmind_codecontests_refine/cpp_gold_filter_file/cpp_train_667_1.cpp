#include <bits/stdc++.h>
using namespace std;
int a[21];
int b[21];
int main() {
  int n, v;
  cin >> n >> v;
  int total = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    total += a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  double mini = 200;
  double bagi;
  for (int i = 1; i <= n; i++) {
    bagi = (double)b[i] / a[i];
    mini = min(mini, bagi);
  }
  double hasil = total * mini;
  if (hasil <= v) {
    cout << fixed << setprecision(4) << hasil << "\n";
  } else
    cout << v << "\n";
}
