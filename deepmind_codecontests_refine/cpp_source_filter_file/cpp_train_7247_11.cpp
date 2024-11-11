#include <bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 7;
char buf[MAXN];
int n, m;
void add(int &x, int y) { x = x + y >= MOD ? x + y - MOD : x + y; }
struct Ac_Automaton {
  int ch[MAXN][26], fail[MAXN], tot, len[MAXN];
  int newnode() {
    tot++;
    memset(ch[tot], 0, sizeof(ch[tot]));
    fail[tot] = len[tot] = 0;
    return tot;
  }
  Ac_Automaton() {
    tot = -1;
    newnode();
  }
  void insert(char *s) {
    int u = 0;
    for (int i = 0; s[i]; i++) {
      int c = s[i] - 'A';
      if (!ch[u][c]) ch[u][c] = newnode();
      u = ch[u][c];
    }
    len[u] = strlen(s);
  }
  void buildFail() {
    queue<int> que;
    for (int c = 0; c < 26; c++)
      if (ch[0][c]) {
        que.push(ch[0][c]);
        fail[ch[0][c]] = 0;
      }
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      len[u] = max(len[u], len[fail[u]]);
      for (int c = 0; c < 26; c++) {
        if (!ch[u][c]) {
          ch[u][c] = ch[fail[u]][c];
          continue;
        }
        que.push(ch[u][c]);
        int v = fail[u];
        while (v and !ch[v][c]) v = fail[v];
        fail[ch[u][c]] = ch[v][c];
      }
    }
  }
  int work(int n) {
    vector<vector<int> > f(tot + 1, vector<int>(11, 0));
    f[0][0] = 1;
    for (int t = 1; t <= n; t++) {
      vector<vector<int> > next_f(tot + 1, vector<int>(11, 0));
      for (int i = 0; i <= tot; i++) {
        for (int mat = 0; mat < 10; mat++) {
          for (int c = 0; c < 26; c++) {
            int nextp = ch[i][c];
            if (len[nextp] >= mat + 1)
              add(next_f[nextp][0], f[i][mat]);
            else
              add(next_f[nextp][mat + 1], f[i][mat]);
          }
        }
      }
      f.swap(next_f);
    }
    int ret = 0;
    for (int i = 0; i <= tot; i++) add(ret, f[i][0]);
    return ret;
  }
} aho;
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%s", buf + 1);
    aho.insert(buf + 1);
  }
  aho.buildFail();
  cout << aho.work(n) << endl;
}
int main() {
  solve();
  return 0;
}
