#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
int n, m, k, num;
char s[maxn];
vector<int> ans[maxn];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (int o = (1), _end_ = (n); o <= _end_; ++o) {
    for (int i = 1; i < n; ++i)
      if (s[i] == 'R' && s[i + 1] == 'L') {
        ans[o].push_back(i);
        swap(s[i], s[i + 1]);
        ++i;
      }
    if (!ans[o].size()) break;
    num += ans[o].size();
    m = o;
  }
  if (m > k || num < k) {
    puts("-1");
    return 0;
  }
  int i = m, x = k;
  num -= k;
  while (num > 0) {
    if (!ans[i].size()) {
      --i;
      continue;
    }
    if (ans[i].size() != 1) --num;
    ans[k--].push_back(ans[i].back());
    ans[i].pop_back();
  }
  for (int i = (1), _end_ = (x); i <= _end_; ++i) {
    printf("%d ", ans[i].size());
    for (int j = (0), _end_ = (ans[i].size() - 1); j <= _end_; ++j)
      printf("%d ", ans[i][j]);
    puts("");
  }
  return 0;
}
