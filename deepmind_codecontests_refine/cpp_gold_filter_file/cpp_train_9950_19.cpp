#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
char a[N], b[N];
int pre[N], suf[N];
queue<int> val[26];
int main() {
  int n, m;
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (int i = 1; i <= n; i++) val[a[i] - 'a'].push(i);
  int tmp = 0;
  for (int i = 1; i <= m; i++) {
    queue<int>& que = val[b[i] - 'a'];
    while (que.size() && que.front() <= tmp) que.pop();
    if (que.empty()) break;
    tmp = que.front();
    pre[tmp] = i;
  }
  for (int i = 1; i <= n; i++)
    if (pre[i] == 0) pre[i] = pre[i - 1];
  for (int i = 0; i <= 25; i++)
    while (val[i].size()) val[i].pop();
  for (int i = n; i >= 1; i--) val[a[i] - 'a'].push(i);
  tmp = n + 1;
  suf[n + 1] = m + 1;
  for (int i = m; i >= 1; i--) {
    queue<int>& que = val[b[i] - 'a'];
    while (que.size() && que.front() >= tmp) que.pop();
    if (que.empty()) break;
    tmp = que.front();
    suf[tmp] = i;
  }
  for (int i = n; i >= 1; i--)
    if (suf[i] == 0) suf[i] = suf[i + 1];
  pair<int, int> ans = pair<int, int>(0, m + 1);
  for (int i = 0; i <= n; i++) {
    if (ans.second - ans.first > suf[i + 1] - pre[i]) {
      ans = pair<int, int>(pre[i], suf[i + 1]);
    }
  }
  if (ans == pair<int, int>(0, m + 1))
    printf("-");
  else if (ans.first >= ans.second)
    printf("%s", b + 1);
  else {
    for (int i = 1; i <= ans.first; i++) printf("%c", b[i]);
    for (int i = ans.second; i <= m; i++) printf("%c", b[i]);
  }
  return 0;
}
