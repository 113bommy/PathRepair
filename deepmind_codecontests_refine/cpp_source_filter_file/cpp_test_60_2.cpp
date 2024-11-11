#include <bits/stdc++.h>
using namespace std;
const int NMAX = 200000;
int a[1 + NMAX];
map<int, int> mp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  a[0] = INT_MIN;
  while (t--) {
    int n;
    cin >> n;
    mp.clear();
    long long suma = 0ll;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      suma += a[i];
      mp[a[i]]++;
    }
    if ((2 * suma) % n) {
      cout << 0 << '\n';
      continue;
    }
    long long medie = 2 * suma / n;
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == medie - a[i])
        sol += mp[medie - a[i]] - 1;
      else
        sol += mp[medie - a[i]];
    }
    cout << sol / 2 << '\n';
  }
  return 0;
}
