#include <bits/stdc++.h>
using namespace std;
const int N = 500004;
int a[N], m, k, s, t, n, sz = 0;
map<int, int> mp, mq;
void add(int n, int val) {
  if (n == -1) return;
  if (val == 1) {
    ++mq[n];
    if (mq[n] == mp[n]) ++sz;
  } else {
    if (mq[n] == mp[n]) --sz;
    --mq[n];
  }
}
int main() {
  scanf("%d %d %d %d", &m, &k, &n, &s);
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= s; i++) {
    scanf("%d", &t);
    ++mp[t];
  }
  for (int i = 1; i <= m; i++)
    if (!mp.count(a[i])) a[i] = -1;
  bool ok = 0;
  vector<int> v;
  for (int l = 1, r = 1; l <= m && !ok; l++) {
    for (; r <= m && sz < mp.size(); r++) add(a[r], 1);
    if (sz >= mp.size()) {
      if ((l - 1) / k + (m - r + 1) / k >= n - 1) {
        ok = 1;
        for (int i = l; i < r; i++) {
          if (a[i] != -1 && mp[a[i]] > 0) {
            --mp[a[i]];
            a[i] = -2;
          }
        }
        for (int i = l; i < r; i++) {
          if (a[i] != -2 && (int)v.size() < r - l - k) v.push_back(i);
        }
        int cnt = (l - 1) % k;
        for (int i = 1; i <= cnt; i++) v.push_back(i);
      }
    }
    add(a[l], -1);
  }
  if (!ok)
    puts("-1");
  else {
    printf("%d\n", v.size());
    for (int x : v) printf("%d ", x);
  }
}
