#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 9;
char str[2][510000], text[1010000];
int n, ans[1010000], num_node, fail[1010000], nxt[1010000], len[1010000],
    to[1010000][26], path[1010000], pa[1010000];
int dl[1010000], last, save[1010000], ie[1010000];
void init() {
  num_node = 2;
  fail[0] = 1;
  len[1] = -1;
  len[0] = 0;
  nxt[0] = 1;
  last = 0;
}
int get_fail(int id, int pos) {
  while (pos - len[id] - 1 >= 1 && text[pos - len[id] - 1] != text[pos])
    id = fail[id];
  return id;
}
void add_letter(int pos) {
  int cur = get_fail(last, pos);
  if (!to[cur][text[pos] - 'a']) {
    len[num_node] = len[cur] + 2;
    fail[num_node] = to[get_fail(fail[cur], pos)][text[pos] - 'a'];
    dl[num_node] = len[num_node] - len[fail[num_node]];
    if (dl[num_node] == dl[fail[num_node]])
      nxt[num_node] = nxt[fail[num_node]];
    else
      nxt[num_node] = fail[num_node];
    to[cur][text[pos] - 'a'] = num_node++;
  }
  last = to[cur][text[pos] - 'a'];
}
int main() {
  scanf("%s%s", str[0], str[1]);
  n = strlen(str[0]);
  int i, j, s, p, q;
  for (i = 0; i < n; i++) {
    text[2 * i] = str[0][i];
    text[2 * i + 1] = str[1][i];
  }
  n *= 2;
  for (i = n - 1; i >= 0; i--) text[i + 1] = text[i];
  init();
  for (i = 1; i <= n; i++) {
    add_letter(i);
    ans[i] = inf;
    for (j = last; len[j] > 0; j = nxt[j]) {
      save[j] = ans[i - len[nxt[j]] - dl[j]];
      path[j] = i - len[nxt[j]] - dl[j];
      if (dl[j] == dl[fail[j]]) {
        if (save[j] > save[fail[j]]) {
          save[j] = save[fail[j]];
          path[j] = path[fail[j]];
        }
      }
      if (!(i & 1)) {
        if (ans[i] > save[j] + 1) {
          ans[i] = save[j];
          pa[i] = path[j];
        }
      }
    }
    if (!(i & 1) && text[i] == text[i - 1]) {
      if (ans[i] > ans[i - 2]) {
        ans[i] = ans[i - 2];
        pa[i] = i - 2;
      }
    }
  }
  if (ans[n] == inf)
    puts("-1");
  else {
    printf("%d\n", ans[n]);
    int id = n;
    while (id > 0) {
      if (pa[id] + 2 != id) printf("%d %d\n", pa[id] / 2 + 1, id / 2);
      id = pa[id];
    }
  }
  return 0;
}
