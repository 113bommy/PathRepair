#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
const int sqn = 350;
bool f[maxn];
int id[maxn], all, cnt[maxn][sqn], ct[maxn];
long long add[sqn], sum[sqn], a[maxn];
vector<int> G[maxn];
vector<int> have[maxn];
int main() {
  int n, m, q;
  while (scanf("%d%d%d", &n, &m, &q) == 3) {
    for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
    all = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d", &ct[i]);
      if (ct[i] >= sqn) {
        f[i] = 1;
        id[i] = all++;
      } else
        f[i] = 0;
      for (int j = 0; j < ct[i]; j++) {
        int t;
        scanf("%d", &t);
        t--;
        G[i].push_back(t);
        if (f[i]) {
          have[t].push_back(all - 1);
          sum[all - 1] += a[i];
        }
      }
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < G[i].size(); j++) {
        int t = G[i][j];
        for (int k = 0; k < have[t].size(); k++) {
          int to = have[t][k];
          cnt[i][to]++;
        }
      }
    char s[10];
    long long op, x;
    while (q--) {
      scanf("%s%I64d", s, &op);
      op--;
      if (s[0] == '?') {
        long long ans = 0;
        if (f[op])
          ans += (long long)sum[id[op]];
        else
          for (int i = 0; i < G[op].size(); i++) ans += (long long)a[G[op][i]];
        for (int i = 0; i < all; i++) ans += (long long)add[i] * cnt[op][i];
        printf("%I64d\n", ans);
      } else {
        scanf("%I64d", &x);
        if (f[op])
          add[id[op]] += x;
        else {
          for (int i = 0; i < G[op].size(); i++) a[G[op][i]] += x;
          for (int i = 0; i < all; i++) sum[i] += (long long)cnt[op][i] * x;
        }
      }
    }
  }
  return 0;
}
