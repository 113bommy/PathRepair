#include <bits/stdc++.h>
using namespace std;
long long n, a[200010], d[200010];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (long long i = (1), _b = (n); i <= _b; i++) cin >> a[i] >> d[i];
  long long ctren = 1000000000000LL;
  long long cduoi = -1000000000000LL;
  long long s = 0;
  for (long long i = (1), _b = (n); i <= _b; i++) {
    if (d[i] == 1)
      cduoi = max(cduoi, 1900 - s);
    else
      ctren = min(ctren, 1900 - s - 1);
    s += a[i];
  }
  if (ctren < cduoi)
    cout << "Impossible";
  else if (ctren == 1000000000000LL)
    cout << "Infinity";
  else
    cout << ctren + s;
  return 0;
}
