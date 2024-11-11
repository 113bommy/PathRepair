#include <bits/stdc++.h>
using namespace std;
const int N = 8e3 + 10;
bitset<N> adj[N], mark;
vector<int> A, B;
long long ans;
int n, p[N];
bool cmp(int u, int v) { return adj[u][v]; }
void remove_super_king() {
  memset(p, -1, sizeof p);
  for (int u = 0; u < n; u++) p[adj[u].count()] = u;
  for (int i = n - 1; ~i && ~p[i]; i--)
    ans += 614 * n * i + i, mark[p[i]] = true;
}
void calc_distance() {
  int ver = -1, pr;
  for (int u = 0; u < n; u++)
    if (!mark[u] && (!~ver || adj[u].count() < adj[ver].count())) ver = pr = u;
  for (int u = 0; u < n; u++)
    if (!mark[u] && u ^ ver)
      if (adj[u][ver])
        if (adj[u][pr])
          A.push_back(pr), pr = u;
        else
          A.push_back(u);
      else
        B.push_back(u);
  sort(A.begin(), A.end(), cmp);
  sort(B.begin(), B.end(), cmp), B.push_back(pr);
  for (int t = 0, cur = -1; t < 2; t++, cur = -1, swap(A, B))
    for (auto u : A) {
      while (cur + 1 < B.size() && adj[u][B[cur + 1]]) cur++;
      for (auto v : A)
        if (u ^ v)
          if (adj[u][v])
            ans++;
          else if (~cur && adj[B[cur]][v])
            ans += 2;
          else
            ans += 3;
      for (auto v : B)
        if (adj[u][v])
          ans++;
        else if (~cur || adj[A.back()][v])
          ans += 2;
        else
          ans += 3;
    }
}
void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n / 4; j++) {
      char c;
      cin >> c;
      int x = c < 'A' ? c - '0' : 10 + c - 'A';
      for (int k = 0; k < 4; k++)
        if (x >> k & 1) adj[i].set(4 * j + 3 - k);
    }
}
void solve() {
  remove_super_king();
  calc_distance();
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve();
  return 0;
}
