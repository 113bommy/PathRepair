#include <bits/stdc++.h>
const int N = 100010;
using namespace std;
struct tree {
  vector<int> a, sumv[4];
  int len;
  void build(int src[], int idx[], int tot) {
    len = tot;
    a.resize(tot + 1);
    for (int i = 0; i < 4; i++) sumv[i].resize(tot + 1);
    for (int i = 1; i <= tot; i++) {
      add(src[i], i, 1);
      a[i] = idx[i];
    }
  }
  int find(int x) {
    int t = lower_bound(a.begin() + 1, a.end(), x) - a.begin();
    return t;
  }
  int ask(int t, int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= ((i) & (-i))) ans += sumv[t][i];
    return ans;
  }
  void add(int t, int x, int v) {
    for (int i = x; i <= len && i > 0; i += ((i) & (-i))) sumv[t][i] += v;
  }
} tre[11][11];
int idx(char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'C') return 2;
  if (c == 'G') return 3;
  return -1;
}
char S[N];
int n;
int a[N], b[N];
void com_change(int x, char ch) {
  for (int len = 1; len <= 10; len++) {
    int j = x % len;
    int t = tre[len][j].find(x);
    tre[len][j].add(idx(S[x - 1]), t, -1);
    tre[len][j].add(idx(ch), t, 1);
  }
  S[x - 1] = ch;
}
int com_ask(int l, int r, char ee[]) {
  int len = strlen(ee);
  int ans = 0;
  for (int i = 0; i < len; i++) {
    int tmp = idx(ee[i]);
    if (l + i > r) continue;
    int j = (l + i) % len;
    int lt = tre[len][j].find(l + i);
    int rt = tre[len][j].find(r + i);
    if (lt == (int)tre[len][j].a.size()) continue;
    if (rt == (int)tre[len][j].a.size() || tre[len][j].a[rt] > r) rt--;
    if (lt <= rt)
      ans += tre[len][j].ask(tmp, rt) - tre[len][j].ask(tmp, lt - 1);
  }
  return ans;
}
int main() {
  scanf("%s", S);
  n = strlen(S);
  int m;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= i; j++) {
      int tot = 0;
      for (int k = j; k <= n; k += i) {
        b[++tot] = k;
        a[tot] = idx(S[k - 1]);
      }
      tre[i][j % i].build(a, b, tot);
    }
  }
  char ee[11];
  scanf("%d", &m);
  int cmd, l, r, x;
  while (m--) {
    scanf("%d", &cmd);
    if (cmd == 1) {
      scanf("%d%s", &x, ee);
      com_change(x, ee[0]);
    } else {
      scanf("%d%d%s", &l, &r, ee);
      printf("%d\n", com_ask(l, r, ee));
    }
  }
}
