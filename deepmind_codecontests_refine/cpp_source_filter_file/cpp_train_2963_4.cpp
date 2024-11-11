#include <bits/stdc++.h>
using namespace std;
map<string, int> order;
string str[100010];
pair<int, int> val[300010], Min[300010];
vector<int> a[300010], A[300010];
stack<int> s;
int n, m, numCnt, groupCnt, inGroup[300010], low[300010], num[300010],
    from[100010], to[100010], f[300010];
bool visit[300010];
int get(string s) {
  if (order.count(s)) return order[s];
  int res = order.size();
  return order[s] = res;
}
void toLower(string &s) {
  int cnt = 0;
  for (int i = (0), _b = (s.length() - 1); i <= _b; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    cnt += (s[i] == 'r');
  }
  val[get(s)] = pair<int, int>(cnt, s.size());
}
void dfs(int u) {
  low[u] = num[u] = ++numCnt;
  s.push(u);
  visit[u] = true;
  for (vector<int>::iterator it = a[u].begin(); it != a[u].end(); it++) {
    int v = *it;
    if (!num[v]) dfs(v);
    if (visit[v]) low[u] = min(low[u], low[v]);
  }
  if (num[u] == low[u]) {
    groupCnt++;
    Min[groupCnt] = pair<int, int>(1000000000, 1000000000);
    int k = -1;
    do {
      k = s.top();
      s.pop();
      Min[groupCnt] = min(Min[groupCnt], val[k]);
      inGroup[k] = groupCnt;
      visit[k] = false;
    } while (k != u);
  }
}
void dfs2(int u) {
  visit[u] = true;
  for (vector<int>::iterator it = A[u].begin(); it != A[u].end(); it++) {
    int v = *it;
    if (!visit[v]) dfs2(v);
    Min[u] = min(Min[u], Min[v]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = (1), _b = (n); i <= _b; i++) {
    cin >> str[i];
    toLower(str[i]);
    f[i] = get(str[i]);
  }
  cin >> m;
  for (int i = (1), _b = (m); i <= _b; i++) {
    string s, t;
    cin >> s >> t;
    toLower(s);
    toLower(t);
    int u = get(s), v = get(t);
    a[u].push_back(v);
    from[i] = u;
    to[i] = v;
  }
  numCnt = 0;
  for (int i = (0), _b = (order.size() - 1); i <= _b; i++)
    if (!num[i]) dfs(i);
  for (int i = (1), _b = (m); i <= _b; i++) {
    int u = inGroup[from[i]];
    int v = inGroup[to[i]];
    if (u != v) A[u].push_back(v);
  }
  for (int i = (1), _b = (groupCnt); i <= _b; i++)
    if (!visit[i]) dfs2(i);
  int cnt = 0;
  int Res = 0;
  for (int i = (1), _b = (n); i <= _b; i++) {
    int u = inGroup[f[i]];
    cnt += Min[u].first;
    Res += Min[u].second;
  }
  cout << cnt << " " << Res;
  return 0;
}
