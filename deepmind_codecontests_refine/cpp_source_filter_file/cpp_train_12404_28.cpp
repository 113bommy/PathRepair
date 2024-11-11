#include <bits/stdc++.h>
using namespace std;
int main() {
  cout << fixed;
  cout << setprecision(0);
  int n, m, r;
  cin >> n >> m >> r;
  int i;
  int min = 10000, max = 0, aux;
  for (i = 0; i < n; i++) {
    cin >> aux;
    if (min > aux) min = aux;
  }
  for (i = 0; i < m; i++) {
    cin >> max;
    if (aux > max) max = aux;
  }
  if (max > min) {
    cout << (int)(r / min) * max + (r % min) << endl;
  } else
    cout << r << endl;
  return 0;
}
