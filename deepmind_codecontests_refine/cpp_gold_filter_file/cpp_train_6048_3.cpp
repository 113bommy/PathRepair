#include <bits/stdc++.h>
using namespace std;
const int desll[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const long long mod = 1e9 + 7;
const int maxn = 3e5 + 7;
const int maxm = 1e8 + 7;
const double eps = 1e-4;
int m, n;
int ar[maxn];
set<pair<long long, int> > se1, se2;
pair<int, pair<long long, int> > pal1[maxn], pal2[maxn];
int le1, le2;
vector<pair<int, int> > e[maxn];
int markl[maxn], mark;
set<pair<int, int> > seMa;
long long ans = 0, ansMid;
int ansl[maxn];
void dfs(int u, int pre) {
  if (u == n) {
    mark = 1;
    markl[u] = 1;
    return;
  }
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i].first;
    if (v == pre) continue;
    dfs(v, u);
    if (mark) {
      markl[u] = 1;
      return;
    }
  }
}
void dfs1(int u, int pre, long long sum, int ins) {
  pal1[le1].first = ins;
  pal1[le1].second.first = sum;
  pal1[le1++].second.second = u;
  if (u == n) {
    ansMid = sum;
  }
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i].first;
    if (v == pre) continue;
    dfs1(v, u, sum + e[u][i].second, ins + markl[v]);
  }
}
void dfs2(int u, int pre, long long sum, int ins) {
  pal2[le2].first = ins;
  pal2[le2].second.first = sum;
  pal2[le2++].second.second = u;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i].first;
    if (v == pre) continue;
    dfs2(v, u, sum + e[u][i].second, ins + markl[v]);
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    e[a].push_back(make_pair(b, c));
    e[b].push_back(make_pair(a, c));
    seMa.insert(make_pair(a, b));
    seMa.insert(make_pair(b, a));
  }
  memset(markl, 0, sizeof(markl));
  mark = 0;
  le1 = le2 = 0;
  ans = 0, ansMid = 0;
  dfs(1, 0);
  dfs1(1, 0, 0, 0);
  dfs2(n, 0, 0, 0);
  sort(pal1, pal1 + le1);
  sort(pal2, pal2 + le2);
  for (int i = 1; i <= n; i++) {
    int ins = 0;
    if (markl[i]) {
      for (int j = 0; j < e[i].size(); j++) {
        int x = e[i][j].first;
        if (markl[x] == 0) ins++;
      }
    } else {
      ins = e[i].size();
    }
    if (ins >= 2) {
      ans = ansMid;
      break;
    }
  }
  int maxNum = pal1[le1 - 1].first;
  int be = 0;
  for (int i = 0; i < le2; i++) {
    if (pal2[i].first == maxNum) break;
    se2.insert(pal2[i].second);
    be = i;
  }
  int ins = 0, res = 0;
  while (res < maxNum) {
    while (pal1[ins].first <= res) {
      se1.insert(pal1[ins].second);
      ins++;
    }
    auto au1 = se1.end();
    auto au2 = se2.end();
    au1--;
    au2--;
    if (seMa.count(make_pair(au1->second, au2->second))) {
      if (au1 != se1.begin()) {
        au1--;
        ans = max(ans, au1->first + au2->first);
        au1++;
      }
      if (au2 != se2.begin()) {
        au2--;
        ans = max(ans, au1->first + au2->first);
        au2++;
      }
    } else
      ans = max(ans, au1->first + au2->first);
    res++;
    while (pal2[be].first + res == maxNum) {
      se2.erase(pal2[be].second);
      be--;
    }
  }
  for (int i = 0; i < m; i++) {
    int ins;
    scanf("%d", &ins);
    printf("%I64d\n", min(ansMid, ans + ins));
  }
  return 0;
}
