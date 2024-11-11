#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
long long a[maxn];
int pos[maxn];
int f[maxn];
int mp[maxn];
int judge(int s, int t) {
  long long x = a[s] * a[t];
  if (x < 0) return 0;
  long long c = sqrt(x);
  if (c * c != x) return 0;
  return 1;
}
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(f, 0, sizeof(f));
    memset(pos, 0, sizeof(pos));
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    int k = 0;
    for (int i = 1; i <= n; i++) {
      if (pos[i]) continue;
      if (a[i] == 0) continue;
      pos[i] = ++k;
      for (int j = i + 1; j <= n; j++) {
        if (a[j] == 0) continue;
        if (judge(i, j)) pos[j] = k;
      }
    }
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      int ji = 0;
      memset(mp, 0, sizeof(int) * (k + 3));
      for (int j = i; j <= n; j++) {
        if (a[j] == 0)
          ji++;
        else if (!mp[pos[j]]) {
          cnt++;
          mp[pos[j]] = 1;
        }
        int x = max(cnt, ji);
        f[x]++;
      }
    }
    for (int i = 1; i <= n; i++) printf("%d%c", f[i], i == n ? '\n' : ' ');
  }
}
