#include <bits/stdc++.h>
using namespace std;
const int N = 300010, LG = 20;
int Q, n, opt, top[2], rt[2][LG], siz[2][LG];
char s[N];
struct ACA {
  int tot, ch[N * 3][26][2], fail[N * 3], cnt[N * 3], vis[N * 3];
  long long sum[N * 3];
  void insert(int p, char *s) {
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
      if (!ch[p][s[i] - 'a'][0]) ch[p][s[i] - 'a'][0] = ++tot;
      p = ch[p][s[i] - 'a'][0];
    }
    cnt[p]++;
  }
  int merge(int x, int y) {
    if (!x || !y) return x | y;
    cnt[x] += cnt[y];
    for (int i = 0; i < 26; i++) ch[x][i][0] = merge(ch[x][i][0], ch[y][i][0]);
    return x;
  }
  void build(int p) {
    queue<int> q;
    for (int i = 0; i < 26; i++)
      if (ch[p][i][0]) {
        q.push(ch[p][i][0]);
        ch[p][i][1] = ch[p][i][0];
        fail[ch[p][i][0]] = p;
      } else
        ch[p][i][1] = p;
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < 26; i++)
        if (ch[u][i][0]) {
          fail[ch[u][i][0]] = ch[fail[u]][i][1];
          ch[u][i][1] = ch[u][i][0];
          q.push(ch[u][i][0]);
        } else
          ch[u][i][1] = ch[fail[u]][i][1];
      sum[u] = cnt[u] + sum[fail[u]];
    }
  }
  long long query(int p, char *s) {
    int len = strlen(s + 1);
    long long ans = 0;
    for (int i = 1; i <= len; i++) {
      p = ch[p][s[i] - 'a'][1];
      ans += sum[p];
    }
    return ans;
  }
} AC;
int main() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d%s", &opt, s + 1);
    if (opt <= 2) {
      opt--;
      top[opt]++;
      siz[opt][top[opt]] = 1;
      rt[opt][top[opt]] = ++AC.tot;
      AC.insert(rt[opt][top[opt]], s);
      for (; siz[opt][top[opt]] == siz[opt][top[opt] - 1]; top[opt]--) {
        AC.merge(rt[opt][top[opt] - 1], rt[opt][top[opt]]);
        siz[opt][top[opt] - 1] *= 2;
      }
      AC.build(rt[opt][top[opt]]);
    } else {
      long long ans = 0;
      for (int i = 1; i <= top[0]; i++) ans += AC.query(rt[0][i], s);
      for (int i = 1; i <= top[1]; i++) ans -= AC.query(rt[1][i], s);
      printf("%lld\n", ans);
      fflush(stdout);
    }
  }
  return 0;
}
