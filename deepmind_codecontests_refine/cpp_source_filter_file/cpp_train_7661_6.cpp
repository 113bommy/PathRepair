#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
struct mb {
  int v, l, r;
  bool operator<(const mb &o) const { return l > o.l; }
};
vector<mb> mp[1000225];
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    int a, b, l, r;
    scanf("%d%d%d%d", &a, &b, &l, &r);
    mp[a << 1].push_back({b << 1 | 1, l, r});
    mp[a << 1 | 1].push_back({b << 1, l, r});
    mp[b << 1].push_back({a << 1 | 1, l, r});
    mp[b << 1 | 1].push_back({a << 1, l, r});
  }
  priority_queue<pair<pair<int, int>, int>,
                 std::vector<pair<pair<int, int>, int>>,
                 std::greater<pair<pair<int, int>, int>>>
      q;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    sort(mp[i << 1].begin(), mp[i << 1].end());
    sort(mp[i << 1 | 1].begin(), mp[i << 1 | 1].end());
  }
  q.push({{0, 0}, 2});
  int ans = (1 << 30);
  while (!q.empty()) {
    auto ppp = q.top();
    q.pop();
    int u = ppp.second;
    pair<int, int> tp = ppp.first;
    if (u / 2 == n) ans = min(ans, tp.first);
    while (!mp[u].empty()) {
      mb z = mp[u].back();
      if (z.l > tp.second) break;
      mp[u].pop_back();
      pair<int, int> tmp = {max(z.l, tp.first), z.r};
      if (z.v % 2 != tmp.first % 2) tmp.first++;
      if (z.v % 2 != tmp.second % 2) tmp.second--;
      if (tmp.second < tmp.first) continue;
      q.push({tmp, z.v});
    }
  }
  if (ans == (1 << 30)) et();
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
