#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, i;
  cin >> q;
  for (i = 0; i < q; i++) {
    long long int n, j;
    double sum = 0;
    cin >> n;
    long long int a[n];
    for (j = 0; j < n; j++) {
      cin >> a[j];
      sum += a[j];
    }
    double x = (double)(sum / n);
    cout << (int)ceil(x) << endl;
  }
}
