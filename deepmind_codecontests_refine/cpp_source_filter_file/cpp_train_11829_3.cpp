#include <bits/stdc++.h>
using namespace std;
struct cock {
  long long a, b, c;
  cock(long long z = -1, long long x = -1, long long v = -1) {
    a = z, b = x, c = v;
  }
};
const long long MAXN = 2e5 + 47;
long long n, m;
vector<vector<long long> > graf(MAXN);
void read() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    --a, --b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
}
vector<bool> us(MAXN, false);
vector<long long> deep(MAXN, 0);
vector<cock> ans;
long long dfs(long long p1) {
  us[p1] = true;
  vector<long long> kek;
  for (long long p2 : graf[p1]) {
    if (us[p2] && deep[p1] > deep[p2]) continue;
    if (us[p2]) {
      kek.push_back(p2);
      continue;
    }
    deep[p2] = deep[p1] + 1;
    long long op = dfs(p2);
    if (op == -1) {
      kek.push_back(p2);
    } else {
      ans.push_back(cock(op, p2, p1));
    }
  }
  while ((long long)(kek.size()) >= 2) {
    long long n = (long long)(kek.size());
    ans.push_back(cock(kek[n], p1, kek[n - 1]));
    kek.pop_back(), kek.pop_back();
  }
  kek.push_back(-1);
  return kek[0];
}
void solve() {
  for (long long i = 0; i < n; i++) {
    if (!us[i]) dfs(i);
  }
  cout << (long long)(ans.size()) << "\n";
  for (cock p : ans)
    cout << p.a + 1 << " " << p.b + 1 << " " << p.c + 1 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    read();
    solve();
  }
}
