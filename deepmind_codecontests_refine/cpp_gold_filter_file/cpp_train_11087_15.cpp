#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, _max;
  vector<long long> h, lux;
  cin >> n;
  h.resize(n);
  lux.resize(n);
  for (long long i = 0; i < n; i++) cin >> h[i];
  lux[n - 1] = 0;
  _max = n - 1;
  for (long long i = n - 2; i >= 0; i--) {
    if (h[i] <= h[_max])
      lux[i] = h[_max] - h[i] + 1;
    else
      lux[i] = 0;
    if (h[i] > h[_max]) _max = i;
  };
  for (long long i = 0; i < n - 1; i++) cout << lux[i] << " ";
  cout << lux[n - 1] << endl;
  return 0;
}
