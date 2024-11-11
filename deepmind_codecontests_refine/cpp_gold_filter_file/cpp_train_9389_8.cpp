#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long Ans;
int Siz[N << 1];
vector<int> Edge[N << 1];
struct SAM {
  int siz, lst;
  struct Node {
    int len, link, nxt[26];
  } t[N << 1];
  inline void Init() { siz = lst = 0, t[0].link = -1; }
  inline void Insert(int c) {
    int cur = ++siz, p = lst;
    t[cur].len = t[p].len + 1;
    while (~p && !t[p].nxt[c]) t[p].nxt[c] = cur, p = t[p].link;
    if (!~p)
      t[cur].link = 0;
    else {
      int q = t[p].nxt[c];
      if (t[p].len + 1 == t[q].len)
        t[cur].link = q;
      else {
        ++siz, t[siz] = t[q], t[siz].len = t[p].len + 1;
        while (~p && t[p].nxt[c] == q) t[p].nxt[c] = siz, p = t[p].link;
        t[q].link = t[cur].link = siz;
      }
    }
    Siz[lst = cur] = 1;
  }
} T;
char str[N];
void dfs(int now) {
  for (int v : Edge[now]) dfs(v), Siz[now] += Siz[v];
  Ans += 1ll * Siz[now] * (Siz[now] + 1) / 2 *
         (T.t[now].len - T.t[T.t[now].link].len);
}
inline void Work() {
  scanf("%s", str + 1);
  int n = strlen(str + 1);
  T.Init();
  for (register int i = 1; i <= n; ++i) T.Insert(str[i] - 'a');
  for (register int i = 1; i <= T.siz; ++i) Edge[T.t[i].link].push_back(i);
  dfs(0);
  cout << Ans << endl;
}
int main() { Work(); }
