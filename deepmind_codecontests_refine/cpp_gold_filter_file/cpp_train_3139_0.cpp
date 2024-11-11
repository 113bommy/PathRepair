#include <bits/stdc++.h>
using namespace std;
long long d[200005];
int main() {
  long long h;
  cin >> h;
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> d[i];
  }
  long long mostNeg = 987654321987654321;
  long long delta = 0;
  for (long long i = 0; i < n; ++i) {
    delta += d[i];
    mostNeg = min(mostNeg, delta);
  }
  if (h + mostNeg <= 0) {
    for (long long i = 0; i < n; ++i) {
      h += d[i];
      if (h <= 0) {
        cout << i + 1 << "\n";
        return 0;
      }
    }
  }
  if (delta >= 0) {
    cout << -1 << "\n";
    return 0;
  }
  double nor = ceil(-1.0 * (h + mostNeg) / delta);
  long long numberOfMinutes = nor * n;
  h += delta * nor;
  for (long long i = 0; i < n; ++i) {
    h += d[i];
    numberOfMinutes++;
    if (h <= 0) {
      cout << numberOfMinutes << "\n";
      return 0;
    }
  }
  while (1)
    ;
  return 0;
}
