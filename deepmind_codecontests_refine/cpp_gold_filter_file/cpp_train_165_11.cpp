#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
vector<int> G[100];
int last[100];
int a[maxn], nex[maxn], pre[maxn];
map<int, int> H;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
      pre[i] = max(pre[i], H[a[i]]);
      for (int j = 0; j < 30; j++) {
        if (a[i] >> j & 1)
          last[j] = i;
        else
          pre[i] = max(pre[i], last[j]);
      }
      H[a[i]] = i;
    }
    for (int i = 0; i < 30; i++) last[i] = n + 1;
    for (int i = n; i > 0; i--) {
      nex[i] = n + 1;
      for (int j = 0; j < 30; j++) {
        if (a[i] >> j & 1)
          last[j] = i;
        else
          nex[i] = min(last[j], nex[i]);
      }
    }
    long long ans = 1LL * n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
      ans -= 1LL * (i - pre[i]) * (nex[i] - i);
    }
    cout << ans << endl;
  }
}
