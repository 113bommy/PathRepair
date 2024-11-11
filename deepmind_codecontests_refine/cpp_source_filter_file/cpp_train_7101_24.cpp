#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
char st[N];
struct Node {
  int len, fa, ch[26];
} a[N];
int k, cur, id[N], node_cnt, cnt[N], n;
long long f[N], s[N];
void ins(int ch) {
  int u = cur;
  cur = ++node_cnt;
  f[cur] = 1;
  a[cur].len = a[u].len + 1;
  for (; u && !a[u].ch[ch]; u = a[u].fa) a[u].ch[ch] = cur;
  if (!u) {
    a[cur].fa = 1;
    return;
  }
  int v = a[u].ch[ch];
  if (a[v].len == a[u].len + 1) {
    a[cur].fa = v;
    return;
  }
  int t = ++node_cnt;
  a[t] = a[v];
  a[t].len = a[u].len + 1;
  a[v].fa = a[cur].fa = t;
  for (; u && a[u].ch[ch] == v; u = a[u].fa) a[u].ch[ch] = t;
}
void print(int u, int k) {
  if (k <= f[u]) return;
  k -= f[u];
  for (int i = 0; i < 26; i++)
    if (k > s[a[u].ch[i]])
      k -= s[a[u].ch[i]];
    else {
      putchar(i + 97);
      print(a[u].ch[i], k);
      return;
    }
}
int main() {
  scanf("%s", st + 1);
  n = strlen(st + 1);
  int len = strlen(st + 1);
  cur = node_cnt = 1;
  for (int i = 1; i <= len; i++) ins(st[i] - 97);
  for (int i = 1; i <= node_cnt; i++) cnt[a[i].len]++;
  for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= node_cnt; i++) id[cnt[a[i].len]--] = i;
  for (int i = node_cnt; i >= 2; i--) f[a[id[i]].fa] += f[id[i]];
  f[1] = 0;
  for (int i = 1; i <= node_cnt; i++) s[i] = f[i];
  for (int i = node_cnt; i >= 1; i--)
    for (int j = 0; j < 26; j++)
      if (a[id[i]].ch[j]) s[id[i]] += s[a[id[i]].ch[j]];
  scanf("%d", &k);
  if (k > s[1])
    puts("No such line");
  else
    print(1, k);
}
