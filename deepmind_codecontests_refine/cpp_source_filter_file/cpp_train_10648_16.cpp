#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int N = 4e5 + 10;
const int base = 2e5 + 5;
const int inf = 1e9;
int n;
int a[N];
int num[N];
int b[N], pre[N];
vector<int> cnt[N];
bool cmp(int x, int y) { return int(cnt[x].size()) > int(cnt[y].size()); }
int main() {
  scanf("%d", &n);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]].push_back(i);
    mx = max(mx, int(cnt[a[i]].size()));
  }
  int d = -1, res = 0;
  for (int i = 1; i <= n; i++)
    if (int(cnt[i].size()) == mx) {
      res++;
      d = i;
    }
  if (res > 1) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1];
    if (a[i] == d) pre[i]++;
  }
  for (int i = 1; i <= n; i++) b[i] = i;
  sort(b + 1, b + n + 1, cmp);
  int ans = 0;
  for (int i = 2; i <= 500; i++)
    if (b[i] != d) {
      memset(num, 0x3f3f3f, sizeof num);
      num[base] = 0;
      int sum = 0;
      for (int k = 1; k <= n; k++) {
        sum += (a[k] == b[i]);
        sum -= (a[k] == d);
        ans = max(ans, k - num[sum + base]);
        num[sum + base] = min(num[sum + base], k);
      }
    }
  for (int i = 501; i <= n; i++)
    if (int(cnt[b[i]].size())) {
      unordered_map<int, int> num;
      num[0] = 0;
      int sum = 0;
      vector<int> v;
      for (int x : cnt[b[i]]) {
        int pos = lower_bound(cnt[d].begin(), cnt[d].end(), x) - cnt[d].begin();
        pos = min(pos, int(cnt[d].size()) - 1);
        for (int j = pos; j >= max(0, pos - int(cnt[b[i]].size()) + 5); j--) {
          v.push_back(cnt[d][j]);
        }
        for (int j = pos;
             j < min(int(cnt[d].size()), pos + int(cnt[b[i]].size()) + 5);
             j++) {
          v.push_back(cnt[d][j]);
        }
        v.push_back(x);
      }
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
      for (int x : v) {
        if (a[x] == b[i]) sum++;
        sum -= pre[x];
        if (num.count(sum))
          ans = max(ans, x - num[sum]);
        else
          num[sum] = x;
        sum += pre[x];
      }
    }
  printf("%d\n", ans);
  return 0;
}
