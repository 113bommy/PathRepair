#include <bits/stdc++.h>
using namespace std;
int n, len, h, a[150001], b[150001], ans;
pair<int, int> f[150001];
bool ok[150001];
int bt[150001], at[150001];
int check(int num) {
  for (int i = 1; i <= num; i++)
    if (at[i] + bt[num - i + 1] < h) return 0;
  return 1;
}
void insert(int& num, int v) {
  num++;
  for (int i = num; i > 1; --i)
    if (v >= at[i - 1]) {
      at[i] = v;
      return;
    } else
      at[i] = at[i - 1];
  at[1] = v;
}
void del(int& num, int v) {
  for (int i = 1; i <= num; i++)
    if (at[i] == v) {
      for (int j = i; j < num; j++) at[i] = at[i + 1];
      break;
    }
  --num;
}
void bruteforce() {
  for (int i = 1; i <= len; i++) bt[i] = b[i];
  int num = 0;
  for (int i = 1; i <= len; i++) insert(num, a[i]);
  ans += check(len);
  for (int i = len + 1; i <= n; i++) {
    del(num, a[i - len]);
    insert(num, a[i]);
    ans += check(len);
  }
  printf("%d\n", ans);
  exit(0);
}
int main() {
  scanf("%d%d%d", &n, &len, &h);
  for (int i = 1; i <= len; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(b + 1, b + len + 1);
  if (len <= 500) bruteforce();
  int y = sqrt(n), x = len - y;
  for (int i = 1; i <= n; i++) f[i] = pair<int, int>(a[i], i);
  sort(f + 1, f + n + 1);
  for (int s = y + 1; s + x - 1 <= n; s += y) {
    memset(ok, true, sizeof(ok));
    int now = 0;
    for (int i = n; i >= 1; --i)
      if (f[i].second >= s && f[i].second <= s + x - 1) {
        for (++now; now <= len && f[i].first + b[now] < h; ++now)
          ;
        if (now <= len) ok[now] = false;
      }
    if (now > len) continue;
    int num = 0, tnum = 0;
    for (int i = 1; i <= len; i++)
      if (ok[i]) bt[++num] = b[i];
    for (int i = s - y; i < s; i++) insert(tnum, a[i]);
    ans += check(num);
    for (int i = s - y + 1; i < s && i + len - 1 <= n; i++) {
      del(tnum, a[i - 1]);
      insert(tnum, a[i + len - 1]);
      ans += check(num);
    }
  }
  printf("%d\n", ans);
}
