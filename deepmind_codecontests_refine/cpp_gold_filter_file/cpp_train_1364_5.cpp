#include <bits/stdc++.h>
using namespace std;
long long n, c[300000], sl, d[300000], e[300000], cnt, Low[300000], Num[300000],
    Count, SL[300000];
vector<long long> a[200005], v[200005];
bool fre[200100];
stack<long long> st;
void visit(int u) {
  Low[u] = Num[u] = ++cnt;
  st.push(u);
  for (int i = 0; i < a[u].size(); i++) {
    long long v = a[u][i];
    if (Num[v])
      Low[u] = min(Low[u], Num[v]);
    else {
      visit(v);
      Low[u] = min(Low[u], Low[v]);
    }
  }
  if (Num[u] == Low[u]) {
    Count++;
    e[Count] = 1e12;
    int v, sl2 = 0;
    do {
      v = st.top();
      st.pop();
      Num[v] = Low[v] = 1e12;
      d[v] = Count;
      e[Count] = min(e[Count], c[v]);
      sl2++;
    } while (v != u);
    SL[Count] = sl2;
  }
}
void dfs(long long u) {
  for (int i = 0; i < a[u].size(); i++) {
    long long v = a[u][i];
    if (d[v] != d[u]) {
      if (SL[d[v]] > 1 && SL[d[u]] > 1) e[u] = min(e[u], e[v]);
      d[v] = d[u], dfs(v);
    }
  }
}
int main() {
  cnt = 0;
  memset(fre, true, sizeof fre);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) {
    long long foo;
    cin >> foo;
    if (i != foo) a[foo].push_back(i);
  }
  long long res = 0;
  for (int i = 1; i <= n; i++)
    if (!Num[i]) visit(i);
  memset(fre, true, sizeof fre);
  for (int i = 1; i <= n; i++) dfs(i);
  for (int i = 1; i <= n; i++) {
    if (fre[d[i]]) res += e[d[i]], fre[d[i]] = false;
  }
  cout << res;
  return 0;
}
