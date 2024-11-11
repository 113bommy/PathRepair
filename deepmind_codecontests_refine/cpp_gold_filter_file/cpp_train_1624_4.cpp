#include <bits/stdc++.h>
using namespace std;
int maxi(int a, int b) {
  if (a > b) return a;
  return b;
}
int mini(int a, int b) {
  if (a < b) return a;
  return b;
}
struct trie {
  int edges[64 + 3], ind;
  int pat_no;
  int pat_len;
};
trie Tri[((15 * 20) + 10)], root;
int len[15];
int tot, f[((15 * 20) + 10)], n, pos[15];
int c[((15 * 20) + 10)];
int getid(char ch) {
  if (ch >= 'a' && ch <= 'z')
    return ch - 'a';
  else if (ch >= 'A' && ch <= 'Z')
    return ch - 'A' + 26;
  else if (ch >= '0' && ch <= '9')
    return ch - '0' + 52;
  if (ch == '_') return 64 - 1;
  return ch - 'a';
}
void init(trie *a, int ind) {
  a->ind = ind;
  a->pat_no = 0;
  a->pat_len = (1 << 29);
  memset(a->edges, -1, sizeof(a->edges));
}
void add(trie *a, char *s, int ind) {
  int i, l, id;
  l = strlen(s);
  for (i = 0; i <= l; i++) {
    if (i == l) {
      pos[ind] = a->ind;
      a->pat_no = ind;
      a->pat_len = mini(a->pat_len, len[ind]);
      continue;
    }
    id = getid(s[i]);
    if (a->edges[id] == -1) {
      a->edges[id] = tot;
      init(&Tri[a->edges[id]], tot++);
    }
    a = &Tri[a->edges[id]];
  }
}
void build() {
  int i, j, piv;
  trie *a = &Tri[0];
  for (i = 0; i <= 64; i++) {
    if (a->edges[i] == -1) a->edges[i] = 0;
  }
  queue<int> q;
  for (i = 0; i <= 64; i++) {
    if (a->edges[i]) {
      f[a->edges[i]] = 0;
      q.push(a->edges[i]);
    }
  }
  while (!q.empty()) {
    int state = q.front();
    q.pop();
    a = &Tri[state];
    for (i = 0; i <= 64; i++) {
      if (a->edges[i] == -1) continue;
      int failure = f[state];
      while (Tri[failure].edges[i] == -1) {
        failure = f[failure];
      }
      failure = Tri[failure].edges[i];
      piv = Tri[state].edges[i];
      f[piv] = failure;
      Tri[piv].pat_len = mini(Tri[piv].pat_len, Tri[failure].pat_len);
      q.push(piv);
    }
  }
}
char s[100100];
char pat[20];
void match(char *s);
int can[100100];
int start[100100];
bool fl[100100];
int dp[100100];
int main() {
  int i, j, k, l, test, t = 1;
  scanf("%s", s);
  scanf("%d", &n);
  c[0] = 0;
  root = Tri[0];
  init(&Tri[0], tot++);
  for (i = 1; i <= n; i++) {
    scanf("%s", pat);
    len[i] = strlen(pat);
    add(&Tri[0], pat, i);
  }
  build();
  int m;
  match(s);
  queue<int> q;
  vector<int> v;
  q.push(0);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    v.push_back(now);
    for (i = 0; i <= 64; i++) {
      if (Tri[now].edges[i] != -1 && Tri[now].edges[i] != 0)
        q.push(Tri[now].edges[i]);
    }
  }
  for (i = v.size() - 1; i >= 0; i--) {
    c[f[v[i]]] += c[v[i]];
  }
  int ans = 0, mark = 0, ans1;
  for (i = 0; s[i]; i++) {
    can[i] = maxi(i - start[i] + 2, 0);
    dp[i] = can[i];
    if (i) dp[i] = maxi(dp[i], dp[i - 1]);
    ans1 = i - dp[i] + 1;
    if (ans1 > ans) {
      ans = ans1;
      mark = dp[i];
    }
  }
  printf("%d %d\n", ans, mark);
  return 0;
}
int find_next(int curr, char ch) {
  int id = getid(ch);
  while (Tri[curr].edges[id] == -1) curr = f[curr];
  return Tri[curr].edges[id];
}
void match(char *s) {
  int i, j, l;
  l = strlen(s);
  int curr = 0;
  for (i = 0; i < l; i++) {
    curr = find_next(curr, s[i]);
    c[curr]++;
    start[i] = Tri[curr].pat_len;
  }
}
