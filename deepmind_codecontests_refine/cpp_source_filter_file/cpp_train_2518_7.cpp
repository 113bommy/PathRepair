#include <bits/stdc++.h>
using namespace std;
char s[4005], t[4005];
int n;
int g[2][2][2];
void calc(char *s, int n, int a[2][2]) {
  for (int i = 1; i <= n; i += 2) {
    int fi = s[i] - '0';
    int se = s[i + 1] - '0';
    a[fi][se]++;
  }
  return;
}
vector<int> vec;
void do_rev(int pos) {
  if (!pos) return;
  assert(pos > 0), assert(!(pos & 1));
  vec.push_back(pos);
  reverse(s + 1, s + pos + 1);
}
void solve(int k) {
  if (k == n) return;
  char fi = t[n - k], se = t[n - k - 1];
  int pos = -1;
  for (int i = k + 1; i <= n; i += 2) {
    if (s[i] == fi && s[i + 1] == se) {
      pos = i - 1;
      break;
    }
  }
  assert(pos >= 0);
  do_rev(pos);
  do_rev(pos + 2);
  solve(k + 2);
  return;
}
int main() {
  int T;
  for (scanf("%d", &T); T--;) {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1);
    memset(g, 0, sizeof g);
    calc(s, n, g[0]);
    calc(t, n, g[1]);
    vec.clear();
    bool flag = 0;
    for (int i = 0; i < 2; i++) {
      if (g[0][i][i] != g[1][i][i]) flag = 1;
    }
    int a[2][2] = {0};
    if (flag) {
      puts("-1");
      continue;
    }
    int pos = 0;
    for (int i = 1; i <= n; i += 2) {
      int fi = s[i] - '0';
      int se = s[i + 1] - '0';
      a[fi][se]++;
      if (a[0][1] + (g[0][1][0] - a[1][0]) == g[1][0][1]) {
        pos = i + 1;
        break;
      }
    }
    if (!pos) {
      memset(a, 0, sizeof a);
      for (int i = 1; i <= n; i += 2) {
        int fi = t[i] - '0';
        int se = t[i + 1] - '0';
        a[fi][se]++;
        if (a[0][1] + (g[1][1][0] - a[1][0]) == g[0][0][1]) {
          pos = -(i + 1);
          break;
        }
      }
    }
    if (pos > 0) {
      do_rev(pos);
      solve(0);
    } else {
      pos = -pos;
      reverse(t + 1, t + pos + 1);
      solve(0);
      vec.push_back(pos);
    }
    int sz = vec.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++) printf("%d%c", vec[i], " \n"[i == sz - 1]);
  }
  return 0;
}
