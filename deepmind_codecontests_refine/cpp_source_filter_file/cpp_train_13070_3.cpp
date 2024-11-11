#include <bits/stdc++.h>
using namespace std;
const int K = 26, LG = 22, MOD = 1e9 + 7, P = 33, SZ = 25e5 + 100,
          CANCER = 25e5;
int lst = 1;
vector<int> lft;
int term[SZ], suff[SZ], par[SZ];
char ch[SZ];
map<int, int> gos[SZ];
bitset<SZ> bts;
int suf(int v);
int go(int v, char c) {
  if (gos[v].find(c) != gos[v].end()) return gos[v][c];
  if (v == par[v]) return v;
  gos[v][c] = go(suf(v), c);
  return gos[v][c];
}
int suf(int v) {
  if (par[par[v]] == par[v]) return par[v];
  if (suff[v] != -1) return suff[v];
  suff[v] = go(suf(par[v]), ch[v]);
  return suff[v];
}
int rootsDel[LG], rootsAdd[LG];
vector<string> added[LG], deled[LG];
int cnt(int v, string& s, int i) {
  if (s.size() == i) return term[v];
  if (gos[v].find(s[i]) == gos[v].end()) return 0;
  return cnt(gos[v][s[i]], s, i + 1);
}
int cnt_add(string& s) {
  int sum = 0;
  for (int i = 0; i < LG; i++) {
    sum += cnt(rootsAdd[i], s, 0);
  }
  return sum;
}
int cnt_del(string& s) {
  int sum = 0;
  for (int i = 0; i < LG; i++) {
    sum += cnt(rootsDel[i], s, 0);
  }
  return sum;
}
void add_aho(int v, string& s, int i) {
  if (i == s.size()) {
    term[v]++;
    return;
  }
  if (gos[v].find(s[i]) == gos[v].end()) {
    lst = lft.back();
    term[lst] = 0;
    ch[lst] = s[i];
    gos[lst].clear();
    bts[lst] = 0;
    suff[lst] = -1;
    par[lst] = v;
    gos[v][s[i]] = lst;
    lft.pop_back();
  }
  add_aho(gos[v][s[i]], s, i + 1);
}
void dfs(int v) {
  lft.push_back(v);
  par[v] = -12;
  for (int i = 0; i < K; i++) {
    if (gos[v].find(i) != gos[v].end()) {
      if (par[gos[v][i]] != -12) dfs(gos[v][i]);
    }
  }
}
vector<string> saved;
void add(string& s) {
  int c = 0;
  for (int i = 0; i < LG; i++) {
    if (added[i].size() == 0) {
      break;
    } else {
      c++;
    }
  }
  saved.clear();
  for (int i = 0; i < c; i++) {
    for (auto& cur : added[i]) saved.push_back(cur);
    dfs(rootsAdd[i]);
    added[i].clear();
    lst = lft.back();
    rootsAdd[i] = lst;
    bts[lst] = 0;
    gos[lst].clear();
    suff[lst] = -1;
    lft.pop_back();
    par[rootsAdd[i]] = rootsAdd[i];
    suff[rootsAdd[i]] = rootsAdd[i];
  }
  par[rootsAdd[c]] = rootsAdd[c];
  suff[rootsAdd[c]] = rootsAdd[c];
  saved.push_back(s);
  for (auto& cur : saved) {
    add_aho(rootsAdd[c], cur, 0);
    added[c].push_back(cur);
  }
}
void del(string& s) {
  int c = 0;
  for (int i = 0; i < LG; i++) {
    if (deled[i].size() == 0) {
      break;
    } else {
      c++;
    }
  }
  saved.clear();
  for (int i = 0; i < c; i++) {
    for (auto& cur : deled[i]) saved.push_back(cur);
    dfs(rootsDel[i]);
    deled[i].clear();
    lst = lft.back();
    rootsDel[i] = lst;
    bts[lst] = 0;
    gos[lst].clear();
    term[lst] = 0;
    par[lst] = lst;
    lft.pop_back();
    par[rootsDel[i]] = rootsDel[i];
    suff[rootsDel[i]] = rootsDel[i];
  }
  saved.push_back(s);
  par[rootsDel[c]] = rootsDel[c];
  suff[rootsDel[c]] = rootsDel[c];
  for (auto& cur : saved) {
    add_aho(rootsDel[c], cur, 0);
    deled[c].push_back(cur);
  }
}
int count(int v) {
  if (!v) return 0;
  if (v == par[v]) return 0;
  if (bts[v]) return term[v];
  term[v] += count(suf(v));
  bts[v] = 1;
  return term[v];
}
int cnt(string& s) {
  int a1 = 0;
  for (int i = 0; i < LG; i++) {
    int v = rootsAdd[i];
    int cnt = 0;
    for (int k = 0; k < s.size(); k++) {
      v = go(v, s[k]);
      cnt += count(v);
    }
    a1 += cnt;
  }
  int a2 = 0;
  for (int i = 0; i < LG; i++) {
    int v = rootsDel[i];
    int cnt = 0;
    for (int k = 0; k < s.size(); k++) {
      v = go(v, s[k]);
      cnt += count(v);
    }
    a2 += cnt;
  }
  return a1 - a2;
}
map<int, char> cnted;
int get_hash(string& s) {
  int cur = 0;
  for (int i = 0; i < s.size(); i++) {
    cur *= P;
    cur += s[i] + 1;
    cur %= MOD;
  }
  return cur;
}
int helpme[26];
int main() {
  int q;
  cin >> q;
  if (q == 0) {
    return 0;
  }
  lst = 1;
  lft.reserve(SZ + 2);
  for (int i = 0; i < SZ; i++) lft.push_back(SZ - i);
  for (int i = 0; i < LG; i++) {
    lst = lft.back();
    lft.pop_back();
    rootsAdd[i] = lst;
    term[lst] = 0;
    bts[lst] = 0;
    par[rootsAdd[i]] = rootsAdd[i];
    suff[rootsAdd[i]] = rootsAdd[i];
    lst = lft.back();
    lft.pop_back();
    rootsDel[i] = lst;
    bts[lst] = 0;
    term[lst] = 0;
    par[rootsDel[i]] = rootsDel[i];
    suff[rootsDel[i]] = rootsDel[i];
  }
  int pr = 0;
  string s;
  while (q--) {
    char type;
    int ctr;
    cin >> ctr >> s;
    if (ctr == 0) {
      type = '+';
    } else if (ctr == 1) {
      type = '-';
    } else {
      type = '?';
    }
    if (s.size() > CANCER) {
      if ((type == '+' || type == '-')) continue;
    }
    for (auto& cur : s) cur -= 'a';
    int p = pr % s.size();
    int hsh = get_hash(s);
    if (type == '+') {
      add(s);
      cnted[hsh]++;
    } else if (type == '-') {
      del(s);
      cnted[hsh]--;
    } else {
      int c = 0;
      for (int i = 0; i < s.size(); i++) c += helpme[s[i]];
      cout << (pr = (cnt(s) + c)) << "\n";
    }
  }
  return 0;
}
