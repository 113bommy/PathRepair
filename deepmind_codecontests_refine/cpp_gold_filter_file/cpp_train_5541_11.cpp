#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m;
  while (cin >> n >> m) {
    long a[100001] = {0}, aa[100010] = {0}, i = 0, j = 0, k = 1, l = 0;
    map<string, int> mp;
    string s;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
      cin >> s;
      if (mp[s] == 0) {
        mp[s] = k++;
      }
      aa[mp[s]]++;
    }
    sort(aa, aa + k);
    long pp = k - 1, x = 0, xx = 0;
    for (int i = 0; i < n; i++) {
      x += aa[pp] * a[i];
      pp--;
      if (pp < 1) break;
    }
    pp = k - 1;
    for (i = n - 1; i >= 0; i--) {
      xx += aa[pp] * a[i];
      pp--;
      if (pp < 1) break;
    }
    cout << x << " " << xx << "\n";
  }
  return 0;
}
