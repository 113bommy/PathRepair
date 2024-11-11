#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int maxm = 3000005;
const int maxlog = 20;
const long long P = 1000000007ll;
const int inf = 2147483647;
const double eps = 1e-6;
const long long INF = 9223372036854775807ll;
int n, mark[maxn], tot;
long long val[20];
void dfs(int cur, int num, int cnt) {
  if (tot == 1000) return;
  if (cur == 14) {
    if (cnt == 6) mark[++tot] = num;
    return;
  }
  if (cnt < 6) dfs(cur + 1, num | (1 << (cur - 1)), cnt + 1);
  if (13 - cur + cnt >= 6) dfs(cur + 1, num, cnt);
}
void prt(int x) {
  bool first = true;
  for (register int i = 12; i >= (0); --i) {
    if ((1 << i) & x) {
      printf("1");
      first = false;
    } else if (first && i)
      printf("*");
    else
      printf("0");
  }
  if (first) printf("0");
  printf("\n");
}
int main() {
  scanf("%d", &n);
  dfs(1, 0, 0);
  vector<int> q;
  for (register int i = 0; i < (13); ++i) {
    q.clear();
    for (register int j = 1; j < (n + 1); ++j) {
      if (!(mark[j] & (1 << i))) {
        q.push_back(j);
      }
    }
    if (!q.empty()) {
      printf("? %d\n", (int)q.size());
      for (register int j = 0; j < (q.size()); ++j) {
        printf("%d ", q[j]);
      }
      printf("\n");
      fflush(stdout);
      scanf("%lld", &val[i]);
    }
  }
  printf("! ");
  for (register int i = 1; i < (n + 1); ++i) {
    long long ans = 0;
    for (register int j = 0; j < (13); ++j) {
      if ((1 << j) & mark[i]) {
        ans |= val[j];
      }
    }
    printf("%lld ", ans);
  }
  fflush(stdout);
}
