#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
const int MAX = 1000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
bool f[26];
bool ff[26];
int fa[26];
int n, m;
int find(int k) {
  if (fa[k] == k) return k;
  return fa[k] = find(fa[k]);
}
void unite(int a, int b) {
  int faa = find(a);
  int fab = find(b);
  if (faa == fab) return;
  fa[faa] = fab;
}
signed main() {
  int n;
  cin >> n;
  for (int i = (0); i <= (25); ++i) fa[i] = i;
  string s;
  getline(cin, s);
  for (int i = (1); i <= (n); ++i) {
    getline(cin, s);
    memset(f, 0, sizeof(f));
    vector<int> tmp;
    for (int j = (0); j <= (s.size() - 1); ++j) {
      if (!f[s[j] - 'a']) {
        tmp.push_back(s[j] - 'a');
        f[s[j] - 'a'] = 1;
      }
      ff[s[j] - 'a'] = 1;
    }
    for (auto j : tmp) {
      for (auto k : tmp) {
        unite(j, k);
      }
    }
  }
  for (int i = (0); i <= (25); ++i) find(i);
  for (int i = (0); i <= (25); ++i)
    if (!ff[i]) fa[i] = 100;
  memset(ff, 0, sizeof(ff));
  for (int i = (0); i <= (25); ++i)
    if (fa[i] != 100) {
      ff[fa[i]] = 1;
    }
  int ans = 0;
  for (int i = (0); i <= (25); ++i)
    if (ff[i]) ans++;
  printf("%d\n", ans);
}
