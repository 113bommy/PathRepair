#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int n;
  long double sum = 0;
  for (int i = 0; i < q; i++) {
    cin >> n;
    long long int a;
    for (int j = 0; j < n; j++) {
      cin >> a;
      sum += a;
    }
    cout << fixed << setprecision(10) << ceil((long double)(sum / n)) << endl;
    sum = 0;
  }
}
