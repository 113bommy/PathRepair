#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
int cases = 1;
map<int, pair<int, int> > add;
string Str[100005], str1, str2;
int M, N;
vector<int> graph[100005], rgraph[100005];
map<string, int> stin;
bool vis[100005];
pair<int, int> save[100005], fut[100005], dp[100005];
int mini_r, mini_l, id, comp[100005];
vector<int> taken;
stack<int> st;
vector<int> tree[100005];
int NOD;
pair<int, int> rec(int u);
void read(void) {
  int len1, len2, r;
  for (int i = 0; i < M; ++i) {
    cin >> Str[i];
  }
  scanf("%d", &N);
  id = 1;
  for (int i = 0; i < N; ++i) {
    cin >> str1 >> str2;
    len1 = str1.size();
    len2 = str2.size();
    r = 0;
    for (int j = 0; j < len1; ++j) {
      str1[j] = tolower(str1[j]);
      if (str1[j] == 'r') r++;
    }
    if (stin.find(str1) == stin.end()) {
      stin[str1] = id;
      add[id] = make_pair(r, len1);
      id++;
    }
    r = 0;
    for (int j = 0; j < len2; ++j) {
      str2[j] = tolower(str2[j]);
      if (str2[j] == 'r') r++;
    }
    if (stin.find(str2) == stin.end()) {
      stin[str2] = id;
      add[id] = make_pair(r, len2);
      id++;
    }
    int u = stin[str1];
    int v = stin[str2];
    rgraph[u].push_back(v);
    graph[v].push_back(u);
  }
  return;
}
void dfs1(int u) {
  vis[u] = 1;
  for (int i = 0; i < (int)graph[u].size(); ++i) {
    int v = graph[u][i];
    if (vis[v] == 0) dfs1(v);
  }
  st.push(u);
  return;
}
void dfs2(int u) {
  vis[u] = 0;
  comp[u] = NOD;
  taken.push_back(u);
  for (int i = 0; i < (int)rgraph[u].size(); ++i) {
    int v = rgraph[u][i];
    if (vis[v] == 1) dfs2(v);
  }
  return;
}
void make_tree(void) {
  for (int i = 1; i < id; ++i) {
    int u = comp[i], v;
    for (int j = 0; j < (int)rgraph[i].size(); ++j) {
      v = comp[rgraph[i][j]];
      if (u == v) continue;
      vis[v] = 1;
      tree[u].push_back(v);
    }
  }
  return;
}
void get_value_for_components(void) {
  int minr = 1000000000, minl = 1000000000;
  pair<int, int> p;
  for (int i = 0; i < (int)taken.size(); ++i) {
    int u = taken[i];
    p = add[u];
    if (p.first < minr)
      minr = p.first, minl = p.second;
    else if (p.first == minr)
      minl = min(minl, p.second);
  }
  save[NOD] = make_pair(minr, minl);
  return;
}
void SCC(void) {
  for (int i = 1; i < id; ++i) {
    if (vis[i] == 0) dfs1(i);
    save[i].first = save[i].second = 1000000000;
  }
  NOD = 1;
  while (!st.empty()) {
    int u = st.top();
    if (vis[u] == 1) {
      taken.clear();
      dfs2(u);
      get_value_for_components();
      NOD++;
    }
    st.pop();
  }
  return;
}
void print(void) {
  long long R = 0, LEN = 0;
  for (int i = 0; i < M; ++i) {
    int len = Str[i].size(), r = 0;
    for (int j = 0; j < len; ++j) {
      Str[i][j] = tolower(Str[i][j]);
      if (Str[i][j] == 'r') r++;
    }
    if (stin.find(Str[i]) == stin.end()) {
      R += r;
      LEN += len;
    } else {
      int u = stin[Str[i]];
      pair<int, int> k = rec(comp[u]);
      R += k.first;
      LEN += k.second;
    }
  }
  cout << R << " " << LEN << endl;
  return;
}
pair<int, int> rec(int u) {
  pair<int, int> &ret = dp[u], tmp;
  if (ret.first != -1) return ret;
  ret = save[u];
  for (int i = 0; i < (int)tree[u].size(); ++i) {
    int v = tree[u][i];
    tmp = rec(v);
    if (tmp.first < ret.first)
      ret = tmp;
    else if (tmp.first == ret.first)
      ret.second = min(ret.second, tmp.second);
  }
  return ret;
}
void call(void) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i < NOD; ++i) {
    if (vis[i] == 0) rec(i);
  }
  return;
}
int main() {
  int test;
  scanf("%d", &M);
  read();
  SCC();
  memset(vis, 0, sizeof(vis));
  make_tree();
  memset(dp, -1, sizeof(dp));
  call();
  print();
  return 0;
}
