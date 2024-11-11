#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
long long fix_mod(long long x, long long y) { return (y + x % y) % y; }
void fast() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
vector<pair<int, double>> v;
int mem[5000][5010];
int solve(int c, int p) {
  if (c == v.size() - 1) return 0;
  int& ret = mem[c][p];
  if (~ret) return ret;
  ret = solve(c + 1, p);
  if (v[c].second > v[p].second) ret = max(ret, solve(c + 1, c) + 1);
  return ret;
}
int main() {
  fast();
  memset(mem, -1, sizeof mem);
  int n, m;
  cin >> n >> m;
  v = vector<pair<int, double>>(n + 1, {0, -1});
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.begin() + n);
  cout << n - solve(0, n) << "\n";
}
