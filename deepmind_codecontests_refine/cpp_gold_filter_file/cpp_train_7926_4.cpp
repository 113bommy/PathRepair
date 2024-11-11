#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n;
long long ans;
string str;
int s[N];
struct node {
  int to;
  int val;
  int next;
} e[N];
int cnt;
int head[N];
bool vis[N];
int col[N];
void add(int u, int v, int val) {
  e[++cnt] = (node){v, val, head[u]};
  head[u] = cnt;
  e[++cnt] = (node){u, val, head[v]};
  head[v] = cnt;
  return;
}
void dfs(int u, int c) {
  col[u] = c;
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = e[i].next)
    if (!vis[e[i].to]) dfs(e[i].to, col[u] ^ e[i].val);
  return;
}
long long qpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % 998244353;
    n >>= 1;
    x = x * x % 998244353;
  }
  return res;
}
void solve(int n, int m) {
  cnt = 0;
  for (int i = 0; i < 2 + n + m; i++) head[i] = -1, vis[i] = 0;
  add(0, 1, 1);
  add(2 + n, 1, 0);
  add(2, 1, 0);
  int t = n / 2;
  for (int i = 0; i < t; i++) add(2 + i, 2 + n - i - 1, 0);
  t = m / 2;
  for (int i = 0; i < t; i++) add(2 + n + i, 2 + n + m - i - 1, 0);
  for (int i = 0; i < n; i++)
    if (s[i] == 1) {
      if (m > i)
        add(2 + i, 2 + n + i, 1);
      else
        add(2 + i, 1, 0);
    } else if (s[i] == 0) {
      if (m > i)
        add(2 + i, 2 + n + i, 0);
      else
        add(2 + i, 0, 0);
    }
  int now = 0;
  for (int i = 0; i < 2 + n + m; i++) {
    if (!vis[i]) {
      dfs(i, 0);
      now++;
    }
  }
  bool flag = 1;
  for (int i = 0; i < 2 + n + m; i++) {
    for (int j = head[i]; j != -1; j = e[j].next) {
      if ((col[i] ^ col[e[j].to]) != e[j].val) flag = 0;
    }
  }
  if (flag) ans = (ans + qpow(2LL, 1LL * now - 1)) % 998244353;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> str;
  for (int i = 0; str[i]; i++) s[i] = str[i] == '?' ? -1 : str[i] - '0';
  n = str.size();
  reverse(s, s + n);
  ans = 0;
  for (int i = 1; i < n; i++) {
    solve(n, i);
  }
  cout << (ans % 998244353 + 998244353) % 998244353 << endl;
  return 0;
}
