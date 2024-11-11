#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long Hashimoto = 0;
  bool Kanna = 1;
  char I_Love = getchar();
  while (I_Love < '0' || I_Love > '9') {
    if (I_Love == '-') Kanna = 0;
    I_Love = getchar();
  }
  while (I_Love >= '0' && I_Love <= '9') {
    Hashimoto = Hashimoto * 10 + I_Love - '0';
    I_Love = getchar();
  }
  return (Kanna ? Hashimoto : -Hashimoto);
}
template <typename T1, typename T2>
inline void Umax(T1 &a, T2 b) {
  if (a < b) a = b;
}
template <typename T1, typename T2>
inline void Umin(T1 &a, T2 b) {
  if (a > b) a = b;
}
struct node {
  int next[4];
  int go[4];
  int link, end, dp_end, f, fc;
  node() {
    memset(next, -1, sizeof(next));
    memset(go, -1, sizeof(go));
    link = end = dp_end = -1;
  }
} v[222];
int vsz = 1;
void add_string(string s) {
  int root = 0;
  for (int i = 0; i < (s.size()); ++i) {
    if (v[root].next[s[i]] == -1) {
      v[root].next[s[i]] = vsz;
      v[vsz].f = root;
      v[vsz].fc = s[i];
      vsz++;
    }
    root = v[root].next[s[i]];
  }
  v[root].end = s.size();
}
int get_link(int vt);
int go(int vt, int c) {
  if (v[vt].go[c] != -1) {
    return v[vt].go[c];
  }
  if (v[vt].next[c] != -1) {
    return v[vt].go[c] = v[vt].next[c];
  }
  return v[vt].go[c] = vt == 0 ? 0 : go(get_link(vt), c);
}
int get_link(int vt) {
  if (v[vt].link != -1) return v[vt].link;
  return v[vt].link =
             (vt == 0 || v[vt].f == 0 ? 0 : go(get_link(v[vt].f), v[vt].fc));
}
int get_end(int vt) {
  int &ret = v[vt].dp_end;
  if (ret != -1) return ret;
  ret = v[vt].end;
  if (vt != get_link(vt)) Umax(ret, get_end(get_link(vt)));
  return ret;
}
int n, m;
int dp[1111][13][222];
int dfs(int pos, int lst, int ver) {
  int need = pos - lst;
  if (need > 11) return 0;
  int &my = dp[pos][pos - lst][ver];
  if (my != -1) return my;
  if (need && get_end(ver) >= need) {
    return my = dfs(pos, pos, ver);
  }
  if (pos == n) {
    if (lst == n)
      return my = 1;
    else
      return my = 0;
  }
  my = 0;
  for (int k = 0; k < (4); ++k) {
    my += dfs(pos + 1, lst, go(ver, k));
    if (my >= (1000000007)) my -= (1000000007);
  }
  return my;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 0; i < (m); ++i) {
    string s;
    cin >> s;
    string FA = "ACGT";
    for (int i = 0; i < (s.size()); ++i) s[i] = FA.find(s[i]);
    add_string(s);
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(0, 0, 0) << endl;
  return 0;
}
