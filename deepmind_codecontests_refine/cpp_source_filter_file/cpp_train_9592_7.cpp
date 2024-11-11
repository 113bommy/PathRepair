#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int add[100005];
int main() {
  int n;
  long long answer = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
  for (int j = 1; j <= n; j++) scanf("%1d", &b[j]);
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      add[i] = b[i] - a[i];
    else
      add[i] = b[i] - a[i] - add[i - 1];
  }
  if (add[n]) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i < n; i++) answer += abs(add[i]);
  long long actual_answer = min(answer, (long long)1e5);
  printf("%lld\n", answer);
  int place, now;
  place = now = 1;
  while (actual_answer--) {
    while (add[place] == 0) ++place, ++now;
    while ((add[now] < 0 && a[now + 1] == 0) ||
           (add[now] > 0 && a[now + 1] == 9))
      now++;
    int change = (add[now] > 0) ? 1 : -1;
    printf("%d %d\n", place, change);
    a[now] += change;
    a[now + 1] += change;
    add[now] -= change;
    now = max(now - 1, place);
  }
  return 0;
}
