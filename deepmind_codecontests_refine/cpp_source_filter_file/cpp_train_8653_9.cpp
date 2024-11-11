#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n, s, cnt[N], son[N];
bool check(long long x) {
  long long now = 1, dep = 1, sum = 0, cnt = 0;
  while (cnt + now <= n) {
    sum += now * dep;
    cnt += now;
    now *= x;
    dep++;
  }
  long long rest = n - cnt;
  sum += rest * dep;
  return sum <= s;
}
long long dep[N];
void init(long long k) {
  long long now = (n + 1) * n / 2, back = n, front = 1;
  for (int i = 1; i <= n; i++) dep[i] = i;
  for (int i = 1; i <= n; i++) cnt[dep[i]]++;
  long long rest = now - s;
  while (rest > 0) {
    if (back - (front + 1) <= rest && cnt[front] * k >= cnt[front + 1] + 1) {
      rest -= (back - (front + 1));
      cnt[back]--;
      cnt[front + 1]++;
      back--;
    } else
      front++;
  }
}
int main() {
  scanf("%lld%lld", &n, &s);
  if (s < n * 2 - 1 || s > (n + 1) * n / 2) {
    puts("NO");
    return 0;
  }
  long long l = 1, r = n - 1, mid, best = -1;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, best = mid;
    else
      l = mid + 1;
  }
  puts("YES");
  init(best);
  int pre = 1, now = 2;
  for (int i = 2; i <= n; i++) {
    int tmp = pre;
    for (int j = 1; j <= cnt[i]; j++) {
      if (son[pre] == mid) pre++;
      printf("%d ", pre);
      son[pre]++;
    }
    pre = tmp + cnt[i - 1];
  }
  return 0;
}
