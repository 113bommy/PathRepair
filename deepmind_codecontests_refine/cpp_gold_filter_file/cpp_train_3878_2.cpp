#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 4e5 + 10;
const int M = 1100;
char s[N];
long long dp[1100][20000];
vector<int> v[20];
namespace AC {
int tr[M][26], tot;
long long val[M], pointval[M], add[M];
int e[M], fail[M], to[M];
void init() {
  memset(tr[0], 0, sizeof tr[0]);
  e[0] = 0;
  tot = 0;
}
void insert(char *s, int v) {
  int u = 0, len = strlen(s);
  for (int i = 0; i < len; i++) {
    int c = s[i] - 'a';
    if (!tr[u][c]) {
      memset(tr[++tot], 0, sizeof tr[tot]);
      e[tot] = 0;
      tr[u][c] = tot;
    }
    u = tr[u][c];
  }
  e[u] = 1;
  val[u] += v;
}
void build() {
  queue<int> q;
  fail[0] = 0;
  for (int i = 0; i < 26; i++)
    if (tr[0][i]) {
      fail[tr[0][i]] = 0;
      q.push(tr[0][i]);
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; i++) {
      if (tr[u][i])
        fail[tr[u][i]] = tr[fail[u]][i], q.push(tr[u][i]);
      else
        tr[u][i] = tr[fail[u]][i];
    }
  }
}
void Pre(int u) {
  for (int i = u; i; i = fail[i]) pointval[u] += val[i];
}
long long solve(char *s) {
  int len = strlen(s), c = 0;
  for (int i = 1; i <= tot; i++) Pre(i);
  for (int i = 0; i <= tot; i++) fill(dp[i], dp[i] + (1 << 15), -inf);
  dp[0][0] = 0;
  for (int i = 0; i <= tot; i++) to[i] = i;
  for (int po = 0; po < len; po++) {
    if (s[po] == '?') {
      c++;
      for (int i = 0; i <= tot; i++)
        for (auto it : v[c - 1]) {
          if (dp[i][it] == -inf) continue;
          for (int j = 0; j < 14; j++) {
            if (it & (1 << j)) continue;
            dp[tr[to[i]][j]][it | (1 << j)] =
                max(dp[tr[to[i]][j]][it | (1 << j)],
                    dp[i][it] + pointval[tr[to[i]][j]] + add[i]);
          }
        }
      for (int i = 0; i <= tot; i++) to[i] = i;
      memset(add, 0, sizeof add);
    } else {
      int c = s[po] - 'a';
      for (int i = 0; i <= tot; i++) {
        to[i] = tr[to[i]][c];
        add[i] += pointval[to[i]];
      }
    }
  }
  long long res = -inf;
  for (int i = 0; i <= tot; i++)
    for (auto j : v[c]) res = max(res, dp[i][j] + add[i]);
  return res;
}
}  // namespace AC
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, val;
  cin >> n;
  AC::init();
  for (int i = 0; i < n; i++) cin >> s >> val, AC::insert(s, val);
  AC::build();
  for (int i = 0; i < (1 << 14); i++) {
    int c = 0;
    for (int j = 0; j < 14; j++)
      if (i & (1 << j)) c++;
    v[c].push_back(i);
  }
  cin >> s;
  cout << AC::solve(s);
  return 0;
}
