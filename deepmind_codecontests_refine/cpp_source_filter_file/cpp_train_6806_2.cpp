#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  deque<int> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    while (q.size() && q.back() < a[i]) {
      if (q.size() >= 2)
        ans = max(ans, q[int(q.size()) - 1] | q[int(q.size()) - 2]);
      q.pop_back();
    }
    q.push_back(a[i]);
  }
  while (q.size() >= 2) {
    ans = max(ans, q[0] | q[1]);
    q.pop_front();
  }
  q.clear();
  for (int i = n; i >= 1; i--) {
    while (q.size() && q.back() < a[i]) {
      if (q.size() >= 2)
        ans = max(ans, q[int(q.size()) - 1] | q[int(q.size()) - 2]);
      q.pop_back();
    }
    q.push_back(a[i]);
  }
  while (q.size() >= 2) {
    ans = max(ans, q[0] | q[1]);
    q.pop_front();
  }
  printf("%d\n", ans);
  return 0;
}
