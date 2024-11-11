#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 401000;
string s1, s2;
vector<int> p1, p2, e[N];
char d0[10], d1[10];
int n, m, x0, x1, rt;
int vis[N], rp[N], po[N];
int minP(string &s) {
  int l = s.length();
  int i = 0, j = 1, k = 0;
  while (i < l && j < l && k < l) {
    if (s[(i + k) % l] == s[(j + k) % l])
      k++;
    else {
      if (s[(i + k) % l] > s[(j + k) % l])
        i += k + 1;
      else
        j += k + 1;
      if (i == j) j++;
      k = 0;
    }
  }
  return min(i, j);
}
int grid(int x, char y) {
  if (y == 'L')
    return x - 1;
  else if (y == 'R')
    return x + n - 1;
  else if (y == 'T')
    return x + n + n - 1;
  else
    return x + n + n + m - 1;
}
char edge(int x) {
  if (x < n)
    return 'L';
  else if (x < n + n)
    return 'R';
  else if (x < n + n + m)
    return 'T';
  else
    return 'B';
}
vector<string> vs;
vector<vector<int> > pp;
bool cmp(int a, int b) { return vs[a] < vs[b]; }
void process(string &s, vector<int> &vp) {
  memset(vis, 0, sizeof(vis));
  vs.clear();
  pp.clear();
  for (int i = 0; i < 2 * (n + m); i++)
    if (!vis[i]) {
      string cs;
      vector<int> cp;
      int p = i, q = e[i][0];
      cp.push_back(p);
      cp.push_back(q);
      while (1) {
        int r = 0;
        r = e[q][p == e[q][0]];
        if (r == i) break;
        cp.push_back(r);
        p = q;
        q = r;
      }
      for (int j = 0; j < ((int)(cp).size()); j++)
        vis[cp[j]] = 1, cs.push_back(edge(cp[j]));
      int p1 = minP(cs);
      string ps1, ps2;
      for (int j = 0; j < ((int)(cs).size()); j++)
        ps1.push_back(cs[(p1 + j) % ((int)(cs).size())]);
      reverse((cs).begin(), (cs).end());
      int p2 = minP(cs);
      for (int j = 0; j < ((int)(cs).size()); j++)
        ps2.push_back(cs[(p2 + j) % ((int)(cs).size())]);
      if (ps1 < ps2) {
        vs.push_back(ps1);
        vector<int> sp;
        for (int j = 0; j < ((int)(ps1).size()); j++)
          sp.push_back(cp[(p1 + j) % ((int)(ps1).size())]);
        pp.push_back(sp);
      } else {
        vs.push_back(ps2);
        reverse((cp).begin(), (cp).end());
        vector<int> sp;
        for (int j = 0; j < ((int)(ps2).size()); j++)
          sp.push_back(cp[(p2 + j) % ((int)(ps2).size())]);
        pp.push_back(sp);
      }
    }
  for (int j = 0; j < ((int)(vs).size()); j++) po[j] = j;
  sort(po, po + ((int)(vs).size()), cmp);
  for (int j = 0; j < ((int)(vs).size()); j++) {
    for (int i = 0; i < ((int)(vs[po[j]]).size()); i++)
      s.push_back(vs[po[j]][i]), vp.push_back(pp[po[j]][i]);
    s.push_back('#');
  }
}
void add(int x, char s, int y, char t) {
  int u = grid(x, s), v = grid(y, t);
  e[u].push_back(v);
  e[v].push_back(u);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n + 1; i++) add(i, 'L', i, 'R');
  for (int i = 1; i < m + 1; i++) add(i, 'T', i, 'B');
  for (int i = 0; i < n + m; i++) {
    scanf("%s%s%d%d", d0, d1, &x0, &x1);
    add(x0, d0[0], x1, d1[0]);
    if ((d0[0] == 'R' && d1[0] == 'T') || (d1[0] == 'R' && d0[0] == 'T')) rt++;
  }
  process(s1, p1);
  for (int i = 0; i < 2 * (n + m); i++) e[i].clear();
  for (int i = 1; i < n + 1; i++) add(i, 'L', i, 'R');
  for (int i = 1; i < m + 1; i++) add(i, 'T', i, 'B');
  if (n < m) {
    for (int i = 0; i < n - rt; i++)
      add(i + 1, 'L', i + 1, 'T'), add(m - i, 'B', n - i, 'R');
    for (int i = 0; i < rt; i++)
      add(n - i, 'L', i + 1, 'B'), add(m - i, 'T', i + 1, 'R');
    for (int i = 0; i < m - n; i++) add(n - rt + i + 1, 'T', rt + 1 + i, 'B');
  } else {
    for (int i = 0; i < m - rt; i++)
      add(i + 1, 'L', i + 1, 'T'), add(m - i, 'B', n - i, 'R');
    for (int i = 0; i < rt; i++)
      add(n - i, 'L', i + 1, 'B'), add(m - i, 'T', i + 1, 'R');
    for (int i = 0; i < n - m; i++) add(m - rt + i + 1, 'L', rt + 1 + i, 'R');
  }
  process(s2, p2);
  if (s1 != s2)
    puts("No solution");
  else {
    for (int j = 0; j < ((int)(p2).size()); j++) rp[p2[j]] = p1[j];
    for (int i = 0; i < n; i++) printf("%d ", rp[i] + 1);
    puts("");
    for (int i = n + n; i < n + n + m; i++) printf("%d ", rp[i] - n - n + 1);
    puts("");
  }
}
