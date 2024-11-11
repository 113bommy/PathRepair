#include <bits/stdc++.h>
using namespace std;
long long t, i, n, res, mx, a[300009];
map<int, int> mp;
int main() {
  cin >> n;
  for (i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= 2 * n; i++) {
    mp[a[i]]++;
    if (mp[a[i]] == 1) {
      res++;
    } else {
      res--;
    }
    if (res >= mx) {
      mx = res;
    }
  }
  cout << mx;
}
