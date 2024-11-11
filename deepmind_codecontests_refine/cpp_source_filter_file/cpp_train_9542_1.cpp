#include <bits/stdc++.h>
using namespace std;
int value[100005];
int main() {
  int n, k, m;
  while (cin >> n >> k >> m) {
    map<string, int> mymap;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      mymap[s] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &value[i]);
    for (int i = 1; i <= k; i++) {
      int cnt, minv = 1000000000;
      int t[100005];
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; j++) {
        scanf("%d", &t[j]);
        minv = min(minv, value[t[j]]);
      }
      for (int j = 0; j < cnt; j++) value[t[j]] = minv;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      ans += value[mymap[s]];
    }
    cout << ans << endl;
  }
}
