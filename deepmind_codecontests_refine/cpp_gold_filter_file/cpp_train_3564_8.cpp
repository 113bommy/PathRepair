#include <bits/stdc++.h>
const long long INF = 1e18;
const long long MOD = 1000000007;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long &i : a) cin >> i;
    for (long long &i : b) cin >> i;
    if (a[0] != b[0]) {
      cout << "NO\n";
      continue;
    }
    vector<map<int, bool> > maps(n);
    map<int, bool> m;
    m[a[0]] = true;
    maps[0] = m;
    for (int i = 1; i < n; i++) {
      maps[i] = maps[i - 1];
      maps[i][a[i]] = true;
    }
    bool sw = false;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        sw = true;
        break;
      }
    }
    if (!sw) {
      cout << "YES\n";
      continue;
    }
    sw = false;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] == b[i]) {
        continue;
      }
      if (a[i] > b[i]) {
        if (maps[i - 1][-1] == true) {
          continue;
        } else {
          cout << "NO\n";
          sw = true;
          break;
        }
      }
      if (a[i] < b[i]) {
        if (maps[i - 1][1] == true) {
          continue;
        } else {
          cout << "NO\n";
          sw = true;
          break;
        }
      }
    }
    if (!sw) cout << "YES\n";
  }
}
