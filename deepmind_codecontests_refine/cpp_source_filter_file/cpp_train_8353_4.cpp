#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int t, n, k, f[N], num[26], cnt[N];
char a[N];
int find(int x) { return x == f[x] ? x : (f[x] = find(f[x])); }
int main() {
  ios::sync_with_stdio(false);
  for (cin >> t; t; t--) {
    cin >> n >> k >> a + 1;
    int ans = 1;
    for (int i = 0; i < 26; i++) num[i] = 0;
    for (int i = 1; i <= n; i++) num[a[i] - 'a']++;
    for (int i = n; i >= 2; i--) {
      for (int j = 1; j <= n; j++) cnt[j] = 0, f[j] = j;
      for (int j = 1; j <= i; j++) {
        int nex = j + k;
        nex %= i;
        if (!nex) nex = i;
        f[find(nex)] = find(j);
      }
      for (int j = 1; j <= i; j++) {
        cnt[find(j)]++;
      }
      sort(cnt + 1, cnt + 1 + i);
      multiset<int> Q;
      for (int j = 0; j < 26; j++) {
        Q.insert(num[j]);
      }
      int st = 0;
      for (int j = i; j >= 1; j--) {
        if (Q.empty()) {
          st = 1;
          break;
        }
        auto x = Q.lower_bound(cnt[j]);
        if (x == Q.end()) {
          st = 1;
          break;
        }
        int y = *x;
        Q.erase(x);
        if (y > cnt[j]) {
          Q.insert(y - cnt[j]);
        }
      }
      if (!st) {
        ans = i;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
