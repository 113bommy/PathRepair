#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 2;
int n, m, a[N], cnt[N], nxt[N];
bool vis[N];
int main() {
  int test;
  cin >> test;
  while (test--) {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) cnt[i] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      int t1 = i + n - a[i], t2 = i - a[i] + 1;
      int k1 = -1, k2 = -1;
      if (t1 < n) {
        k1 = t1;
      }
      if (t2 > 0) {
        k2 = t2 - 1;
      }
      if (k1 >= 0) ++cnt[k1];
      if (k2 >= 0) cnt[k2] += k1 != k2;
    }
    vector<int> ans;
    ans.clear();
    for (int i = 0; i < n; ++i) {
      if (n - cnt[i] > m * 2) continue;
      for (int j = 1; j <= n; ++j) {
        vis[j] = false;
        if (a[j] <= n - i) {
          nxt[j] = i + a[j];
        } else {
          nxt[j] = a[j] - (n - i);
        }
      }
      int cycles = 0;
      for (int j = 1; j <= n; ++j)
        if (nxt[j] != j && !vis[j]) {
          int u = j;
          ++cycles;
          vis[j] = true;
          while (nxt[u] != j) {
            u = nxt[u];
            vis[u] = true;
          }
        }
      if (n - cnt[i] - cycles <= m) {
        ans.push_back(i);
      }
    }
    cout << (int)ans.size() << " ";
    for (int i : ans) cout << i << " ";
    cout << endl;
  }
  return 0;
}
