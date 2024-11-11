#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, minn = 101, maxx = 0, locM, locm;
  cin >> n;
  int niz[n];
  for (int i = 1; i <= n; i++) {
    cin >> niz[i];
    if (niz[i] >= maxx) {
      maxx = niz[i];
      locM = i;
    }
    if (niz[i] <= minn) {
      minn = niz[i];
      locm = i;
    }
  }
  int res = (n - locm) + locM - 1;
  if (locm < locM) res--;
  cout << res;
  return 0;
}
