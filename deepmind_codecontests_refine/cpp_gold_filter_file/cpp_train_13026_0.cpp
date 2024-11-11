#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 150;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
int a[N], cnt[N], ans[N];
bool st[N][N], st1[N];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int fg = 0;
  for (int i = 1; i <= 5000; i++)
    if (cnt[i] > k) fg = 1;
  if (fg)
    cout << "NO" << endl;
  else {
    map<int, int> mp;
    int idx = 1;
    for (int i = 0; i < n; i++) {
      if (!mp[a[i]] && idx <= k) {
        mp[a[i]]++;
        st[a[i]][idx] = true;
        st1[idx] = true;
        ans[i] = idx++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!ans[i]) {
        int idx = -1;
        for (int j = k; j >= 1; j--) {
          if (!st1[j]) {
            idx = j;
            break;
          }
        }
        if (idx == -1) idx = k;
        for (int j = idx; j >= 1; j--) {
          if (!st[a[i]][j]) {
            st[a[i]][j] = true;
            st1[j] = true;
            ans[i] = j;
            break;
          }
        }
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  solve();
  return 0;
}
