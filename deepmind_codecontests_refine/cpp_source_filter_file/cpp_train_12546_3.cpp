#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool l = 0;
  long long int a[n], sum = 0, cont = 0, sum1 = 0;
  vector<long long int> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    l = 1;
    if (a[0] % 2 != 0) {
      cout << "0" << endl;
    } else {
      cout << a[0] << endl;
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        sum = sum + a[i];
      } else {
        x.push_back(a[i]);
        cont++;
        sum = sum + a[i];
      }
    }
  }
  if (cont > 1) {
    if (cont % 2 == 0) {
      sum = sum + sum1;
    } else {
      sum = sum + sum1 - *min_element(x.begin(), x.end());
    }
  }
  if (l == 0) cout << sum << endl;
  return 0;
}
