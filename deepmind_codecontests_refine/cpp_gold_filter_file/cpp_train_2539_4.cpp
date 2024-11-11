#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
inline string get() {
  char ch[2000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 21;
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const int base = 29;
const int mod = 1e9 + 7;
int nxt[maxn][40], link[maxn], len[maxn], sz = 1, lst = 0, betId = 27, l[15],
                                          r[15], cnt[maxn][15];
inline void add_letter(int ch) {
  int p = lst;
  lst = sz++;
  len[lst] = len[p] + 1;
  for (; nxt[p][ch] == 0; p = link[p]) nxt[p][ch] = lst;
  if (nxt[p][ch] == lst) {
    assert(p == 0);
    link[lst] = 0;
    return;
  }
  int q = nxt[p][ch];
  if (len[q] == len[p] + 1) {
    link[lst] = q;
    return;
  }
  int cl = sz++;
  memcpy(nxt[cl], nxt[q], sizeof nxt[q]);
  link[cl] = link[q];
  link[q] = link[lst] = cl;
  len[cl] = len[p] + 1;
  for (; nxt[p][ch] == q; p = link[p]) nxt[p][ch] = cl;
}
bool mark[maxn];
inline void dfs(int node) {
  if (mark[node]) return;
  mark[node] = true;
  for (int i = 0; i < 40; i++) {
    if (!nxt[node][i]) continue;
    dfs(nxt[node][i]);
    if (i > 26) {
      cnt[node][i - 27]++;
    } else if (i != 26) {
      for (int j = 0; j < 10; j++) cnt[node][j] += cnt[nxt[node][i]][j];
    }
  }
}
long long res;
bool mark2[maxn];
vector<int> nodes;
string save;
int sizeofs;
inline void doJob(string &s, int pos = 0, int node = 0) {
  if (pos == sizeofs) return;
  node = nxt[node][s[pos] - 'a'];
  int cur = node;
  do {
    nodes.push_back(cur);
    mark2[cur] = true;
    cur = link[cur];
  } while (mark2[cur] == false);
  doJob(s, pos + 1, node);
}
int32_t main() {
  string s = get();
  for (int i = 0; i < s.size(); i++) add_letter(s[i] - 'a');
  save = s;
  sizeofs = (int)s.size();
  int n = in();
  add_letter(26);
  for (int i = 0; i < n; i++) {
    string s = get();
    l[i] = in(), r[i] = in();
    for (int j = 0; j < s.size(); j++) add_letter(s[j] - 'a');
    add_letter(betId++);
  }
  dfs(0);
  doJob(save, 0);
  for (int node : nodes) {
    int numbers = len[node] - len[link[node]];
    bool ok = true;
    for (int j = 0; j < 10; j++) {
      ok &= cnt[node][j] >= l[j] && cnt[node][j] <= r[j];
    }
    if (ok) res += numbers;
  }
  cout << res << "\n";
}
