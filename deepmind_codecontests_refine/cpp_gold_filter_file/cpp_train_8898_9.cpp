#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxk = 30;
const int INF = 1e9;
int f[maxn];
char s[maxn], t[maxn], ans[maxn];
int n, k;
void getfail(char *s, int len_s) {
  f[0] = f[1] = 0;
  for (int i = 1; i < len_s; i++) {
    int j = f[i];
    while (j && s[i] != s[j]) j = f[j];
    f[i + 1] = (s[i] == s[j]) ? j + 1 : 0;
  }
}
void solve() {
  scanf("%d %d", &n, &k);
  scanf("%s", s);
  scanf("%s", t);
  int len_s = strlen(s), len_t = strlen(t);
  getfail(s, len_s);
  queue<int> q;
  int last = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == '1') q.push(i);
    if (!q.empty()) {
      int u = q.front();
      ans[i] = s[i - u];
      last = i - u + 1;
      if (i == u + len_s - 1) q.pop();
    } else {
      int pos = INF;
      for (int j = 0; j < k; j++) {
        int now = last;
        while (now && j + 'a' != s[now]) now = f[now];
        if (j + 'a' == s[now]) now++;
        if (now < pos) {
          pos = now;
          ans[i] = j + 'a';
        }
      }
      last = pos;
    }
  }
  ans[n] = '\0';
  for (int i = 0; i < n - len_s + 1; i++) {
    int flag = 1;
    for (int j = 0; j < len_s; j++) {
      if (ans[i + j] != s[j]) {
        flag = 0;
        break;
      }
    }
    if (t[i] - '0' != flag) {
      printf("No solution\n");
      goto nxt;
    }
  }
  printf("%s\n", ans);
nxt:;
}
int main() {
  solve();
  return 0;
}
