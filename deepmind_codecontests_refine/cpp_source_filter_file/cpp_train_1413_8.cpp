#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int maxN = 510000;
int n;
vector<int> g[maxN], w[maxN];
unordered_map<int, int> *s[maxN];
int shift[maxN], len[maxN];
int res[maxN];
bool cmp(pair<int, int> x, pair<int, int> y) {
  return s[x.first]->size() > s[y.first]->size();
}
void dfs(int v) {
  for (int i = 0; i < g[v].size(); ++i) {
    dfs(g[v][i]);
    res[v] = max(res[v], res[g[v][i]]);
  }
  if (g[v].size() == 0) {
    s[v] = new unordered_map<int, int>();
    (*s[v])[0] = 0;
    shift[v] = 0;
    res[v] = 0;
    return;
  }
  vector<pair<int, int> > children;
  for (int i = 0; i < g[v].size(); ++i) {
    children.push_back(make_pair(g[v][i], w[v][i]));
  }
  sort(children.begin(), children.end(), cmp);
  s[v] = s[children[0].first];
  shift[v] = shift[children[0].first];
  shift[v] ^= (1 << children[0].second);
  len[v] = len[children[0].first];
  ++len[v];
  reverse(children.begin(), children.end());
  for (int i = 0; i + 1 < children.size(); ++i) {
    int u = children[i].first;
    int c = children[i].second;
    shift[u] ^= (1 << c);
    ++len[u];
    for (unordered_map<int, int>::iterator it = s[u]->begin();
         it != s[u]->end(); ++it) {
      int current = (shift[v] ^ shift[u] ^ (it->first));
      int l = len[u] + len[v] + it->second;
      unordered_map<int, int>::iterator jt = s[v]->find(current);
      if (jt != s[v]->end()) {
        res[v] = max(res[v], jt->second + l);
      }
      for (int j = 0; j < 'v' - 'a'; ++j) {
        jt = s[v]->find(current ^ (1 << j));
        if (jt != s[v]->end()) {
          res[v] = max(res[v], jt->second + l);
        }
      }
    }
    for (unordered_map<int, int>::iterator it = s[u]->begin();
         it != s[u]->end(); ++it) {
      int current = (shift[u] ^ shift[v] ^ it->first);
      int value = it->second + len[u] - len[v];
      if (s[v]->count(current)) {
        (*s[v])[current] = max((*s[v])[current], value);
      } else {
        (*s[v])[current] = value;
      }
    }
  }
  unordered_map<int, int>::iterator it = s[v]->find(shift[v]);
  if (it != s[v]->end()) {
    res[v] = max(res[v], it->second + len[v]);
  }
  for (int j = 0; j < 'v' - 'a'; ++j) {
    it = s[v]->find(shift[v] ^ (1 << j));
    if (it != s[v]->end()) {
      res[v] = max(res[v], len[v] + it->second);
    }
  }
  if (s[v]->count(shift[v])) {
    (*s[v])[shift[v]] = max((*s[v])[shift[v]], -len[v]);
  } else {
    (*s[v])[shift[v]] = -len[v];
  }
}
void gen() {
  n = 500000;
  for (int i = 1; i < n; ++i) {
    int v = rand() % i + 1;
    g[v].push_back(i + 1);
    w[v].push_back(rand() % ('v' - 'a' + 1));
  }
}
char ss[15];
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 15; ++j) {
      ss[j] = 0;
    }
    gets(ss);
    int l = strlen(ss);
    int v = 0;
    char c = ss[l - 1];
    for (int j = 0; j < l - 2; ++j) {
      v = v * 10 + (ss[j] - '0');
    }
    g[v].push_back(i + 1);
    w[v].push_back(c - 'a');
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", res[i]);
  }
  printf("\n");
  cerr << clock() << endl;
  return 0;
}
