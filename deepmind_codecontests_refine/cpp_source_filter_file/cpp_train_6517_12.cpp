#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100012;
int n, a[SIZE];
deque<int> q[SIZE];
void Init(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    q[a[i]].push_back(i);
  }
  return;
}
void Solve(void) {
  long long pos = 0, ans = 0, cnt = 1;
  for (int i = 1; i <= 100001; ++i) {
    if (q[i].empty()) continue;
    deque<int>::iterator iter = lower_bound(q[i].begin(), q[i].end(), pos);
    ans += cnt * (q[i].end() - iter);
    pos = q[i].back();
    q[i].erase(iter, q[i].end());
    if (!q[i].empty()) {
      pos = 0;
      ++cnt;
      --i;
    }
  }
  printf("%d", ans);
  return;
}
int main(void) {
  Init();
  Solve();
  return 0;
}
