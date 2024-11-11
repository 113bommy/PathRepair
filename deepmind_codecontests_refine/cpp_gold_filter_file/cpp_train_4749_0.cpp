#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long x, aux, con = 1, res = 0;
  cin >> aux;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int c = 1; c < n; c++) {
    cin >> x;
    if (aux == x)
      con++;
    else {
      for (int k = 1; k <= con; k++) res += k;
      con = 1;
    }
    if (c == n - 1) {
      for (int k = 1; k <= con; k++) res += k;
    }
    aux = x;
  }
  cout << res;
}
