#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
const int OO = 0x3f3f3f3f;
const double eps = 1e-8;
int C[maxn];
int num[maxn];
vector<pair<int, int> > V;
priority_queue<int> Q;
vector<int> g[maxn];
int Len[maxn], Cost[maxn];
vector<int> L;
int main() {
  while (!Q.empty()) Q.pop();
  memset(num, 0, sizeof(num));
  memset(C, 0, sizeof(C));
  L.clear();
  V.clear();
  int n;
  scanf("%d", &n);
  int len, cost;
  int sum = 0;
  int Max = 0;
  for (int i = 0; i < n; i++) scanf("%d", &Len[i]), Max = max(Len[i], Max);
  for (int i = 0; i <= Max; i++) g[i].clear();
  for (int i = 0; i < n; i++) scanf("%d", &Cost[i]);
  for (int i = 0; i < n; i++) {
    len = Len[i];
    cost = Cost[i];
    num[len]++;
    C[len] += cost;
    g[len].push_back(cost);
    sum += cost;
  }
  V.clear();
  for (int i = 1; i <= Max; i++)
    if (num[i] > 0) {
      V.push_back(make_pair(num[i], C[i]));
      L.push_back(i);
    }
  int sz = V.size();
  int ans = OO;
  int ans1 = 0;
  vector<int> t;
  for (int i = 0; i < sz; i++) {
    ans1 = sum - V[i].second;
    int x = V[i].first;
    int sub = 0;
    t.clear();
    while (!Q.empty() && x >= 2) {
      int u = Q.top();
      sub += u;
      Q.pop();
      t.push_back(u);
      x--;
    }
    for (int j = 0; j < t.size(); j++) Q.push(t[j]);
    for (int j = 0; j < g[L[i]].size(); j++) {
      Q.push(g[L[i]][j]);
    }
    ans = min(ans, ans1 - sub);
  }
  printf("%d\n", ans);
  return 0;
}
