#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
int n, x[maxn], y[maxn], cnt;
char a[maxn], b[maxn];
std::pair<int, int> ans[maxn];
void add(int);
void sub(int);
void add(int i) {
  if (i == n) {
    puts("-2");
    exit(0);
  }
  if (x[i + 1] == 9) sub(i + 1);
  ++x[i];
  ++x[i + 1];
  ans[++cnt] = std::pair<int, int>(i, 1);
}
void sub(int i) {
  if (i == n) {
    puts("-2");
    exit(0);
  }
  if (x[i + 1] == 0) add(i + 1);
  --x[i];
  --x[i + 1];
  ans[++cnt] = std::pair<int, int>(i, -1);
}
long long chk() {
  long long tot = 0;
  int d;
  for (int i = 1; i <= n; ++i) {
    x[i] = a[i] - '0';
    y[i] = b[i] - '0';
  }
  for (int i = 1; i < n; ++i) {
    if (x[i] < 0) {
      d = -x[i];
      x[i] += d;
      x[i + 1] += d;
      tot += d;
    }
    if (x[i] > 9) {
      d = x[i] - 9;
      x[i] -= d;
      x[i + 1] -= d;
      tot += d;
    }
    while (x[i] < y[i]) {
      ++x[i];
      ++x[i + 1];
      ++tot;
    }
    while (x[i] > y[i]) {
      --x[i];
      --x[i + 1];
      ++tot;
    }
  }
  if (x[n] != y[n]) {
    puts("-1");
    exit(0);
  }
  return tot;
}
int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; ++i) {
    x[i] = a[i] - '0';
    y[i] = b[i] - '0';
  }
  for (int i = 1; i <= n; ++i) {
    while (x[i] < y[i] && cnt < 1e5) add(i);
    while (x[i] > y[i] && cnt < 1e5) sub(i);
  }
  printf("%lld\n", chk());
  for (int i = 1; i <= cnt && i <= 1e5; ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
