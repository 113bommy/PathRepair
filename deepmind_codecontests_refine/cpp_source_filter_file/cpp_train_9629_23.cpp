#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0;
  int neg;
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9' || ch == '-') {
      if (ch == '-')
        neg = -1;
      else
        neg = 1, res = ch - '0';
      break;
    }
  }
  while (true) {
    char ch = getchar();
    if (ch >= '0' && ch <= '9')
      res *= 10, res += ch - '0';
    else
      break;
  }
  return res * neg;
}
const int maxn = 500020;
const int maxm = 1000020;
const int MOd = 1e3;
int a, b, dad[maxn];
char ar[maxn];
bool ans[maxn];
vector<pair<int, int> > q[maxn];
vector<int> w[maxn];
set<pair<int, int> > st[maxn];
void insert(set<pair<int, int> > &st, pair<int, int> t) {
  set<pair<int, int> >::iterator it = st.find(t);
  if (it != st.end())
    st.erase(it);
  else
    st.insert(t);
}
void dfs(int n, int s) {
  for (int i = 0; i < w[n].size(); i++) {
    dfs(w[n][i], s + 1);
    int t = w[n][i];
    if (st[n].size() < st[t].size()) swap(st[n], st[t]);
    for (set<pair<int, int> >::iterator it = st[t].begin(); it != st[t].end();
         it++) {
      insert(st[n], *it);
    }
  }
  insert(st[n], pair<int, int>(s, ar[n] - 'a'));
  for (int i = 0; i < q[n].size(); i++) {
    set<pair<int, int> >::iterator it =
        st[n].lower_bound(pair<int, int>(q[n][i].first, 0));
    int h = 0;
    while (h <= 1 && it != st[n].end() && it->first == q[n][i].first) h++, it++;
    if (h <= 1) ans[q[n][i].second] = 1;
  }
}
int main() {
  scanf("%d %d", &a, &b);
  for (int i = 2; i <= a; i++) {
    scanf("%d", &dad[i]);
    w[dad[i]].push_back(i);
  }
  scanf(" %s", ar + 1);
  for (int i = 1; i <= b; i++) {
    int v, h;
    scanf("%d %d", &v, &h);
    q[v].push_back(pair<int, int>(h, i));
  }
  dfs(1, 1);
  for (int i = 1; i <= b; i++) {
    if (ans[i])
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
