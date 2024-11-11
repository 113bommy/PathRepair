#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, w, aux, cont = 0, min = 0, max = 0;
  cin >> n >> w;
  for (long long i = 0; i < n; i++) {
    cin >> aux;
    cont += aux;
    if (min > cont) min = cont;
    if (max < cont) max = cont;
  }
  if (max > w) {
    cout << 0 << '\n';
    return 0;
  }
  min = (min < 0) ? -min : 0;
  max = (max <= 0) ? w : w - max;
  long long dif = max - min;
  cout << ((dif <= 0) ? 0 : (dif + 1)) << '\n';
  return 0;
}
