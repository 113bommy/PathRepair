#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, mxn = 2e5 + 5;
int n;
int a[200005];
int mp1[200005], mp2[200005];
map<int, int> mp;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int ele, ma = 0;
  for (auto ii : mp) {
    if (ma < ii.second) {
      ma = ii.second;
      ele = ii.first;
    }
  }
  int an = 0;
  for (int i = 1; i <= 100; i++) {
    if (ele == i) continue;
    memset(mp1, -1, sizeof(mp1));
    memset(mp2, -1, sizeof(mp2));
    int su = 0;
    mp1[0] = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == ele)
        su++;
      else if (a[j] == i)
        su--;
      if (su >= 0) {
        if (mp1[su] != -1) {
          int idx = mp1[su];
          int tm = j + 1 - idx;
          an = max(tm, an);
        } else {
          mp1[su] = j + 1;
        }
      } else {
        if (mp2[-1 * su] != -1) {
          int idx = mp2[-1 * su];
          int tm = j + 1 - idx;
          an = max(tm, an);
        } else {
          mp2[-1 * su] = j + 1;
        }
      }
    }
  }
  cout << an;
  return 0;
}
