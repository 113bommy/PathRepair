#include <bits/stdc++.h>
using namespace std;
const int maxn = 7000 + 10;
const int maxm = 1e5 + 10;
const long long mod = 1e9 + 7;
const int inf = 0x3fffffff;
long long n, a[maxn], b[maxn];
bool vis[62];
bool v[maxn][70];
map<long long, int> m1;
set<long long> s;
long long res = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m1[a[i]]++;
    for (long long j = 60; j >= 0; j--)
      v[i][j] = (a[i] & (1LL << j)) == 0 ? false : true;
    if (m1[a[i]] >= 2) s.insert(a[i]);
  }
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (m1[a[i]] >= 2)
      res += b[i];
    else {
      for (auto p = s.begin(); p != s.end(); p++) {
        bool flag = true;
        long long temp = (*p);
        if (temp > a[i]) continue;
        for (int k = 60; k >= 0; k--) {
          if ((a[i] & (1LL << k)) != 0 && (temp & (1LL << k)) == 0) {
            flag = false;
            break;
          }
        }
        if (flag) {
          res += b[i];
          break;
        }
      }
    }
  }
  cout << res;
  return ~~(0 - 0);
}
