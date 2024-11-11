#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e5 + 7;
bitset<N> E[41], zero;
long long e[41];
int c1 = 0, c2 = 0;
map<string, int> mps;
int n, m, op;
int res = 0;
void dfs(int c, int now, long long S) {
  res = max(res, now);
  if (m - c + now <= res) return;
  for (int i = c; i < c2; i++)
    if (!(S & e[i])) dfs(i + 1, now + 1, S | 1 << i);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  string temp;
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == 1) {
      c1++;
    } else {
      cin >> temp;
      if (mps.find(temp) == mps.end()) mps[temp] = c2++;
      int id = mps[temp];
      if (c1) E[id][c1] = 1;
    }
  }
  for (int i = 0; i < c2; i++) {
    e[i] |= 1ll << i;
    for (int j = i + 1; j < c2; j++)
      if ((E[i] & E[j]) != zero) e[i] |= 1ll << j, e[j] |= 1ll << i;
  }
  dfs(0, 0, 0);
  cout << res << endl;
  return 0;
}
