#include <bits/stdc++.h>
using namespace std;
int n, f[100005], w[100005], minimum[100005];
vector<int> GT[100005];
bool uz[100005], in[100005];
long long k, sum[100005];
void DFS(int u, int p, vector<int> &cycle, map<int, long long> &values,
         long long S, int last, vector<int> &st, long long nCycle) {
  sum[u] = S;
  minimum[u] = values.begin()->first;
  st.push_back(u);
  long long newS;
  if (nCycle == 0) last = 1;
  int lastNode = (nCycle <= 0)
                     ? st[last]
                     : ((last - 1 >= 0) ? cycle[last - 1] : cycle.back());
  int newLast;
  if (nCycle <= 0)
    newLast = last + 1;
  else {
    newLast = last - 1;
    if (newLast < 0) newLast += (int)cycle.size();
  }
  for (auto x : GT[u]) {
    if (x == p) continue;
    newS = S + w[x];
    newS -= w[lastNode];
    ++values[w[x]];
    if (--values[w[lastNode]] == 0) values.erase(w[lastNode]);
    DFS(x, u, cycle, values, newS, newLast, st, nCycle - 1);
    if (--values[w[x]] == 0) values.erase(w[x]);
    ++values[w[lastNode]];
  }
  st.pop_back();
}
void solve(int u) {
  int x = u;
  vector<int> st;
  vector<int> cycle;
  while (!uz[x]) {
    st.push_back(x);
    uz[x] = 1;
    in[x] = 1;
    x = f[x];
  }
  bool cycleFound = in[x];
  for (auto x : st) in[x] = 0;
  if (!cycleFound) return;
  long long cycleSum = 0;
  int y = x;
  do {
    cycle.push_back(y);
    cycleSum += w[y];
    y = f[y];
  } while (y != x);
  int n = (int)cycle.size();
  int last = k % n;
  if (last < 0) last += n;
  map<int, long long> values;
  long long sum = k / n * cycleSum;
  if (k >= n) {
    for (int i = 0; i < n; ++i) values[w[cycle[i]]] = k / n;
  }
  for (int i = 0; i < last; ++i) {
    sum += w[cycle[i]];
    ++values[w[cycle[i]]];
  }
  for (int i = 0; i < n; ++i) {
    vector<int> st;
    DFS(cycle[i], ((i - 1 >= 0) ? cycle[i - 1] : cycle.back()), cycle, values,
        sum, last, st, k);
    sum += w[cycle[last]];
    sum -= w[cycle[i]];
    ++values[w[cycle[last]]];
    if (--values[w[cycle[i]]] == 0) values.erase(w[cycle[i]]);
    if (++last >= n) last -= n;
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &f[i]);
    ++f[i];
    GT[f[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  for (int i = 1; i <= n; ++i)
    if (!uz[i]) solve(i);
  for (int i = 1; i <= n; ++i) printf("%I64d %d\n", sum[i], minimum[i]);
  return 0;
}
