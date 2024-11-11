#include <bits/stdc++.h>
using namespace std;
int n, s, a[200001], cnt[200000];
deque<int> dq;
int main() {
  int ans = 0;
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (a[s] != 0) a[s] = 0, ans++;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) cnt[a[i]]++;
  int mx = a[n];
  for (int i = 0; i <= mx; i++)
    if (cnt[i] == 0) dq.push_back(i);
  while (cnt[0] > 1) {
    ans++;
    if (!dq.empty()) dq.pop_front();
    cnt[0]--;
  }
  for (int i = mx; i >= 0; i--) {
    if (cnt[i] == 0) continue;
    while (!dq.empty() && dq.back() > i) dq.pop_back();
    if (dq.empty()) break;
    dq.pop_front();
    ans++;
    cnt[i]--;
  }
  printf("%d", ans);
  return 0;
}
