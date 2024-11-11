#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q;
  cin >> n >> q;
  n = (long long)(1 << n);
  int ar[n];
  double sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    sum += ar[i];
  }
  cout << fixed << setprecision(10);
  cout << sum / n << endl;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    sum += b - a;
    ar[a] = b;
    cout << fixed << setprecision(10) << sum / n << endl;
  }
  return 0;
}
