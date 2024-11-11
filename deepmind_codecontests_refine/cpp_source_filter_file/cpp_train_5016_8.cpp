#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int maxn = 2e5 + 5;
int P[maxn];
vector<int> G[maxn], G1[maxn];
int dfn[maxn], low[maxn];
int id;
int color;
int belong[maxn];
int in[maxn];
bool ins[maxn];
stack<int> st;
int n, m;
int f[maxn];
void solve();
void tarjan(int a);
bool topsort();
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) scanf("%d", &P[j]);
    for (int j = 1; j < n; j++) G[P[j]].push_back(P[j + 1]);
  }
  solve();
  if (topsort()) {
    printf("YES\n");
    for (int i = 1; i <= n; i++) putchar('a' + min(f[belong[i]], m));
    putchar(10);
  } else
    printf("NO\n");
  return 0;
}
void solve() {
  id = color = 0;
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; i++) {
    const int &a = belong[i];
    for (int j = 0; j < G[i].size(); j++) {
      const int &b = belong[G[i][j]];
      if (a != b) {
        G1[a].push_back(b);
        in[b]++;
      }
    }
  }
}
void tarjan(int a) {
  dfn[a] = low[a] = ++id;
  st.push(a);
  ins[a] = true;
  for (int i = 0; i < G[a].size(); i++) {
    const int &b = G[a][i];
    if (!dfn[b]) {
      tarjan(b);
      low[a] = min(low[a], low[b]);
    } else if (ins[b])
      low[a] = min(low[a], low[b]);
  }
  if (dfn[a] == low[a]) {
    color++;
    int b;
    do {
      b = st.top();
      st.pop();
      ins[b] = false;
      belong[b] = color;
    } while (b != a);
  }
}
bool topsort() {
  while (!st.empty()) st.pop();
  for (int i = 1; i <= color; i++) {
    if (!in[i]) {
      st.push(i);
      f[i] = 0;
    }
  }
  int mx = -1;
  while (!st.empty()) {
    int a = st.top();
    st.pop();
    mx = max(mx, f[a]);
    for (int i = 0; i < G1[a].size(); i++) {
      const int &b = G1[a][i];
      f[b] = max(f[b], f[a] + 1);
      in[b]--;
      if (!in[b]) st.push(b);
    }
  }
  return mx + 1 >= m;
}
