#include <bits/stdc++.h>
using namespace std;
int const bound = 5e6 + 2, N = 6e5 + 2;
long long OO = 1e18;
int oo = 1e9, mod = oo + 7;
pair<int, int> aa[N];
int main() {
  int n;
  cin >> n;
  for (int(i) = 0; (i) < (n); (i)++) cin >> aa[i].first >> aa[i].second;
  sort(aa, aa + n);
  int e = -1, d = -1;
  for (int(i) = 0; (i) < (n); (i)++) {
    if (e < aa[i].first)
      e = aa[i].second;
    else if (d < aa[i].first)
      d = aa[i].second;
    else {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
