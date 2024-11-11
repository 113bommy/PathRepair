#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e5) + 100;
int n;
int answer;
int f[maxn], up[maxn];
int a[maxn];
int BIT[maxn];
bool flag[maxn];
vector<int> ans[maxn];
void read() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}
void insert(int cur, int v) {
  for (; cur <= n; cur += (-cur) & cur) BIT[cur] = max(BIT[cur], v);
}
int ask(int cur) {
  int s = 0;
  for (; cur; cur -= (-cur) & cur) s = max(s, BIT[cur]);
  return s;
}
void clear(int cur) {
  for (; cur <= n; cur += (-cur) & cur) BIT[cur] = 0;
}
void dfs(int n) {
  if (n == 0) return;
  for (int i = 1; i <= n; ++i) {
    f[i] = ask(a[i]) + 1;
    insert(a[i], f[i]);
  }
  for (int i = 1; i <= n; ++i) clear(a[i]);
  int ansf = 1;
  for (int i = 1; i <= n; ++i)
    if (f[i] > f[ansf]) ansf = i;
  int tmp = 0;
  int k = sqrt(n * 2);
  while (k * (k + 1) < n * 2) ++k;
  if (f[ansf] >= k) {
    int w = ansf;
    flag[w] = true;
    for (int i = w - 1; i > 0; --i)
      if (f[i] == f[w] - 1 && a[i] < a[w]) flag[w = i] = true;
    ++answer;
    for (int i = 1; i <= ansf; ++i)
      if (flag[i]) ans[answer].push_back(a[i]);
    for (int i = 1; i <= n; ++i)
      if (flag[i])
        flag[i] = false;
      else
        a[++tmp] = a[i];
    dfs(tmp);
  } else {
    for (int i = 1; i <= n; ++i) {
      int cur = upper_bound(up + 1, up + 1 + tmp, a[i]) - up;
      if (cur > tmp) ++tmp;
      ans[answer + cur].push_back(a[i]);
      up[cur] = a[i];
    }
    answer += tmp;
    return;
  }
}
void solve() {
  for (int i = 1; i <= n; ++i) flag[i] = false;
  answer = 0;
  dfs(n);
  printf("%d\n", answer);
  for (int i = 1; i <= answer; ++i) {
    printf("%d", ans[i].size());
    for (auto &j : ans[i]) printf(" %d", j);
    puts("");
    ans[i].clear();
  }
}
int main() {
  int casesum;
  scanf("%d", &casesum);
  while (casesum--) {
    read();
    solve();
  }
  return 0;
}
