#include <bits/stdc++.h>
using namespace std;
const long long Llinf = LLONG_MAX;
const int Inf = INT_MAX;
const int Maxn = 1e5 + 10;
const int Mod = 1e9 + 7;
char* _c = new char[Maxn];
string GetString() {
  scanf("%s", _c);
  return string(_c);
}
int n, a, b, k, f;
map<pair<string, string>, int> m;
string pre = "";
int ans;
int pntr;
int cost[500];
int GetC(string s, string t) {
  if (!m[make_pair(s, t)] && !m[make_pair(t, s)])
    return m[make_pair(s, t)] = ++pntr;
  else
    return (m[make_pair(s, t)]) ? m[make_pair(s, t)] : m[make_pair(t, s)];
}
int main() {
  scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
  for (int i = 0; i < n; i++) {
    string s = GetString(), t = GetString();
    if (s == pre)
      cost[GetC(s, t)] += b;
    else
      cost[GetC(s, t)] += a;
    pre = t;
  }
  sort(cost + 1, cost + pntr, greater<int>());
  for (int i = 1; i <= pntr && k; i++)
    if (cost[i] > f) k--, cost[i] = f;
  for (int i = 1; i <= pntr; i++) ans += cost[i];
  printf("%d\n", ans);
  return 0;
}
