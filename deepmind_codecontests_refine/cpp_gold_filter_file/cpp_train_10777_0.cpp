#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100000 + 10;
const int P = 4079;
const int MOD = 1000000009;
map<string, int> hmap, pmap;
string hs[MAX_N], ps[MAX_N];
int hids[MAX_N], pids[MAX_N], pes[MAX_N], hshs[MAX_N];
set<int> psets[MAX_N];
pair<int, int> hps[MAX_N];
vector<int> vs[MAX_N];
int alloc_id(map<string, int> &mp, string ss[], string &s, int &n) {
  map<string, int>::iterator mit = mp.find(s);
  if (mit != mp.end()) return mit->second;
  ss[n] = s;
  return (mp[s] = n++);
}
int set2hash(set<int> &s) {
  int h = 0;
  for (set<int>::iterator sit = s.begin(); sit != s.end(); sit++)
    h = (h + pes[*sit]) % MOD;
  return h;
}
int main() {
  int hn = 0, pn = 0;
  string empty;
  alloc_id(pmap, ps, empty, pn);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char s[128];
    scanf("%s", s);
    char *cpt = s + 7, *cpt1 = cpt;
    while (*cpt1 && *cpt1 != '/') cpt1++;
    string sh(cpt, cpt1);
    hids[i] = alloc_id(hmap, hs, sh, hn);
    string sp(cpt1);
    pids[i] = alloc_id(pmap, ps, sp, pn);
    psets[hids[i]].insert(pids[i]);
  }
  pes[0] = 1;
  for (int i = 0; i < pn; i++) pes[i + 1] = (long long)pes[i] * P % MOD;
  for (int i = 0; i < hn; i++) {
    hshs[i] = set2hash(psets[i]);
    int sz = psets[i].size();
    hps[i] = pair<int, int>(sz, hshs[i]);
  }
  sort(hps, hps + hn);
  int m = unique(hps, hps + hn) - hps;
  for (int i = 0; i < hn; i++) {
    int sz = psets[i].size();
    int l = lower_bound(hps, hps + m, pair<int, int>(sz, hshs[i])) - hps;
    vs[l].push_back(i);
  }
  int k = 0;
  for (int i = 0; i < m; i++)
    if (vs[i].size() > 1) k++;
  printf("%d\n", k);
  for (int i = 0; i < m; i++)
    if (vs[i].size() > 1) {
      for (int j = 0; j < vs[i].size(); j++) {
        printf("http://%s", hs[vs[i][j]].c_str());
        putchar(j + 1 < vs[i].size() ? ' ' : '\n');
      }
    }
  return 0;
}
