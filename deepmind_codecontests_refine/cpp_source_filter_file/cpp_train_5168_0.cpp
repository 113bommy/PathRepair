#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int t[n], m[n], i, minimo;
  for (i = 0; i < n; i++) {
    cin >> t[i];
    m[i] = t[i];
  }
  sort(t, t + n);
  minimo = t[0];
  long long int flag = 0, first, second, d, maximo = 10000000000;
  for (i = 0; i < n; i++) {
    if (m[i] == minimo) {
      if (flag == 0) {
        flag = 1;
        second = i;
        continue;
      }
      first = second;
      second = i;
      d = second - first;
      if (d < maximo) {
        maximo = d;
      }
    }
  }
  cout << d << endl;
  return 0;
}
