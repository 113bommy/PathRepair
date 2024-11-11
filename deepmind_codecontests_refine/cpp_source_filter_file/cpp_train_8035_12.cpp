#include <bits/stdc++.h>
using namespace std;
const long long sz = 3e5 + 5;
int a[sz], f[sz], l[sz];
map<int, int> mp;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), mp[a[i]] = 1;
    int k = 0;
    for (auto it : mp) mp[it.first] = ++k;
    for (int i = 0; i < n; i++) a[i] = mp[a[i]];
    mp.clear();
    for (int i = 0; i < n; i++) f[i] = 0;
    for (int i = 0; i < n; i++) {
      int x = a[i];
      if (!f[x]) f[x] = i + 1;
      l[x] = i + 1;
    }
    int ans = 1, cur = 1;
    for (int i = k - 1; i; i--) {
      if (l[i] < f[i + 1])
        cur++;
      else
        cur = 1;
      ans = max(ans, cur);
    }
    printf("%d\n", k - ans);
  }
}
