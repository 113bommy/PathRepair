#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 500;
struct operation {
  int tp, x;
} op[maxn];
int n, m, a[maxn], ans[maxn], event[maxn];
vector<int> s, vi;
int main(int argc, char *argv[]) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &op[i].tp, &op[i].x);
  for (int i = 1; i <= m; ++i) {
    while (s.size() && op[s.back()].x <= op[i].x) s.pop_back();
    s.push_back(i);
  }
  deque<int> vx;
  for (int i = op[s[0]].x + 1; i <= n; ++i) ans[i] = a[i];
  for (int i = 1; i <= op[s[0]].x; ++i) vi.push_back(a[i]);
  sort(vi.begin(), vi.end());
  for (int i = 0; i < vi.size(); ++i) vx.push_back(vi[i]);
  memset(event, -1, sizeof(event));
  for (int i = 0; i < s.size(); ++i) event[op[s[i]].x] = op[s[i]].tp;
  int cur = 0;
  for (int i = op[s[0]].x; i >= 1; --i) {
    if (~event[i]) cur = event[i];
    if (cur == 1)
      ans[i] = vx.back(), vx.pop_back();
    else
      ans[i] = vx.front(), vx.pop_front();
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
