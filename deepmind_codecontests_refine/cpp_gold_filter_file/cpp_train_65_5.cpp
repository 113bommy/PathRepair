#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename... t>
using V = vector<t...>;
template <typename... t>
using outit = ostream_iterator<t...>;
void print(ostream& os) { os << '\n'; }
template <typename t, typename... v>
void print(ostream& os, const t& a, v&&... b) {
  os << a << ' ';
  print(os, b...);
}
int n;
V<int> odp;
V<int> ilo, poz;
V<V<int> > gr;
V<V<bool> > dp;
bool dfs1(int v, int oj) {
  if (static_cast<int>((gr[v]).size()) == 1 and v != oj) return dp[1][v] = true;
  for (int s : gr[v])
    if (s != oj)
      if (not dfs1(s, v)) return false;
  for (int s : gr[v])
    if (s != oj) {
      if (dp[0][s] and dp[1][s])
        ilo[v] = s;
      else if (dp[1][s])
        ++poz[v];
    }
  dp[0][v] = ((poz[v] & 1) == 1) or ilo[v] != -1;
  dp[1][v] = ((poz[v] & 1) == 0) or ilo[v] != -1;
  if ((not dp[0][v] and not dp[1][v]) or (v == oj and not dp[1][v]))
    return false;
  return true;
}
void dfs2(int v, int oj, bool fl = false) {
  bool zm = false;
  if (fl == false and (poz[v] & 1) == 1) zm = true;
  if (fl == true and (poz[v] & 1) == 0) zm = true;
  for (int s : gr[v])
    if (s != oj) {
      if (zm and s == ilo[v]) continue;
      if (dp[0][s]) dfs2(s, v, false);
    }
  odp.push_back(v);
  for (int s : gr[v])
    if (s != oj) {
      if (zm and s == ilo[v]) {
        dfs2(s, v, true);
        continue;
      }
      if (dp[0][s] == false and dp[1][s] == true) dfs2(s, v, true);
    }
}
int main(int argc, char** argv) {
  (void)(argc);
  (void)(argv);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  gr.resize(n + 1);
  ilo.resize(n + 1, -1);
  poz.resize(n + 1);
  dp.resize(2, V<bool>(n + 1));
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if (p != 0) {
      gr[i].push_back(p);
      gr[p].push_back(i);
    }
  }
  if (not dfs1(1, 1)) return print(cout, "NO"), 0;
  ;
  dfs2(1, 1);
  print(cout, "YES");
  copy(begin(odp), end(odp), outit<int>(cout, "\n"));
}
