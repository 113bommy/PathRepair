#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 3;
const int maxm = 1e6 + 3;
const int mod = 1e9 + 7;
const int oo = 1061109567;
const long long loo = 4557430888798830399;
const long double pi = 3.141592653589793238462643383279502884;
void input() {
  if (fopen("abc"
            ".inp",
            "r")) {
    freopen(
        "abc"
        ".inp",
        "r", stdin);
    freopen(
        "abc"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, k, last = 0, sz = 1;
string s;
int link[maxn], len[maxn], to[maxn][26], terminal[maxn];
long long occ[maxn], word[maxn];
void ins(int c) {
  int id = sz++;
  len[id] = len[last] + 1;
  for (; last != -1 && !to[last][c]; last = link[last]) to[last][c] = id;
  if (last != -1) {
    int p = to[last][c];
    if (len[p] == len[last] + 1)
      link[id] = p;
    else {
      int q = sz++;
      len[q] = len[last] + 1;
      link[q] = link[p];
      memcpy(to[q], to[p], sizeof(to[p]));
      for (; last != -1 && to[last][c] == p; last = link[last]) to[last][c] = q;
      link[id] = link[p] = q;
    }
  }
  last = id;
}
void dfs(int u) {
  if (occ[u] != 0) return;
  occ[u] += terminal[u];
  word[u] += terminal[u];
  for (int i = 0; i < 26; ++i) {
    int v = to[u][i];
    if (!v) continue;
    dfs(v);
    occ[u] += occ[v];
    word[u] += occ[v] + word[v];
  }
}
int main() {
  input();
  cin >> s >> k;
  int n = s.size();
  if (k > n * (n + 1) / 2) {
    cout << "No such line.";
    return 0;
  }
  link[0] = -1;
  for (int i = 0; i < s.size(); ++i) ins(s[i] - 'a');
  while (last) {
    terminal[last] = 1;
    last = link[last];
  }
  dfs(0);
  string ans = "";
  int u = 0;
  while (k > 0) {
    long long cur = 0;
    for (int i = 0; i < 26; ++i) {
      int v = to[u][i], pre = cur;
      if (!v) continue;
      cur += word[v];
      if (cur >= k) {
        u = v;
        k -= pre + occ[v];
        ans += char('a' + i);
        break;
      }
    }
  }
  cout << ans;
  return 0;
}
