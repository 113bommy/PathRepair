#include <bits/stdc++.h>
using namespace std;
const long long MAXD = 5e2 + 6.9;
const long long MAXS = 5e3 + 69;
struct vl {
  long long mod, sum;
};
long long d, s;
long long lastdigit[MAXD][MAXS];
vl last[MAXD][MAXS];
void bfs() {
  for (long long mod = 0; mod < d; mod++)
    for (long long sum = 0; sum <= s; sum++) lastdigit[mod][sum] = -1;
  queue<vl> q;
  for (long long i = 1; i <= 9; i++) lastdigit[i % d][i] = i, q.push({i, i});
  while (!q.empty()) {
    long long mod = q.front().mod;
    long long sum = q.front().sum;
    q.pop();
    for (long long nex = 0; nex <= 9; nex++) {
      long long nmod = (mod * 10 + nex) % d;
      long long nsum = sum + nex;
      if (nsum > s || lastdigit[nmod][nsum] != -1) continue;
      lastdigit[nmod][nsum] = nex;
      last[nmod][nsum] = {mod, sum};
      q.push({nmod, nsum});
    }
  }
}
void tray(vl u) {
  if (lastdigit[u.mod][u.sum] != -1) {
    tray(last[u.mod][u.sum]);
    cout << lastdigit[u.mod][u.sum];
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> d >> s;
  bfs();
  if (lastdigit[0][s] == -1)
    cout << -1;
  else
    tray({0, s});
}
