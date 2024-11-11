#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long n, i, j;
  cin >> n;
  long long mn, mx;
  vector<pair<long long, long long> > v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  long long f = 1;
  if (v[0].second == 1) {
    mn = 1900, mx = 100000000000000000;
  } else {
    mn = 1000000000000000000, mx = 1899;
  }
  for (i = 0; i < n; i++) {
    if (v[i].second == 1)
      mn = max((long long)1900, mn);
    else
      mx = min(mx, (long long)1899);
    if (mn > mx) {
      f = 2;
      break;
    }
    mn += v[i].first;
    mx += v[i].first;
  }
  if (f == 2 || mx < mn)
    cout << "Impossible";
  else if (mx > 10000000000)
    cout << "Infinity";
  else
    cout << mx;
}
