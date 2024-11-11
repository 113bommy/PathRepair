#include <bits/stdc++.h>
using namespace std;
int n;
long long sxor, p[65], a[100005];
vector<long long> bit[65];
int main() {
  int i, j, nr, ok;
  long long x;
  cin >> n;
  p[0] = 1;
  for (i = 1; i <= 60; i++) p[i] = p[i - 1] * 2;
  for (i = 1; i <= n; i++) {
    cin >> x;
    sxor ^= x;
    j = 60;
    while ((j >= 0) && (!(p[j] & x))) j--;
    bit[j].push_back(x);
  }
  nr = n + 1;
  for (i = 1; i <= n; i++) {
    ok = 0;
    for (j = 0; (j <= 60) && (!ok); j++)
      if ((p[j] & sxor) && (!bit[j].empty())) {
        nr--;
        a[nr] = bit[j].back();
        bit[j].pop_back();
        ok = 1;
      }
    if (!ok) {
      cout << "No";
      return 0;
    }
    sxor ^= a[nr];
  }
  cout << "Yes"
       << "\n";
  for (i = 1; i <= n; i++) cout << a[i] << ' ';
  return 0;
}
