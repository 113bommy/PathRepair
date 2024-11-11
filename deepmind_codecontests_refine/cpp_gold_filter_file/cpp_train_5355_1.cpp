#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
long long sum[2 * 311111];
int a, b, c[2 * 311111], cnt[2 * 311111];
pair<int, int> p[2 * 311111];
long long que(int x) {
  long long re = 0;
  while (x) {
    re += sum[x];
    x -= ((x) & (-(x)));
  }
  return re;
}
void add(int x, int qd) {
  while (x < 2 * 311111) {
    sum[x] += qd;
    x += ((x) & (-(x)));
  }
}
int main() {
  int t, x, y, z, ca = 1;
  scanf("%d%d", &(n), &(m));
  for (int i = (int)(1); i <= (int)(n); ++i) {
    scanf("%d%d", &(a), &(b));
    p[2 * i] = make_pair(a, b);
    p[2 * i - 1] = make_pair(b, a);
    cnt[a]++, cnt[b]++;
  }
  sort(p + 1, p + 2 * n + 1);
  for (int i = (int)(1); i <= (int)(2 * n); ++i) c[i] = p[i].first;
  for (int i = (int)(1); i <= (int)(n); ++i) add(cnt[i] + 1, 1);
  int l, r;
  long long ans = 0;
  for (int i = (int)(1); i <= (int)(n); ++i) {
    z = cnt[i], y = i;
    l = lower_bound(c + 1, c + 2 * n + 1, y) - c;
    r = upper_bound(c + 1, c + 2 * n + 1, y) - c;
    for (int j = (int)(l); j <= (int)(r - 1); ++j) {
      add(cnt[p[j].second] + 1, -1);
      add(cnt[p[j].second], 1);
      cnt[p[j].second]--;
    }
    ans += n - (m - z > 0 ? que(m - z) : 0);
    if (m - z <= z) ans--;
    for (int j = (int)(l); j <= (int)(r - 1); ++j) {
      add(cnt[p[j].second] + 1, -1);
      add(cnt[p[j].second] + 2, 1);
      cnt[p[j].second]++;
    }
  }
  printf("%I64d\n", (ans >> 1));
  return 0;
}
