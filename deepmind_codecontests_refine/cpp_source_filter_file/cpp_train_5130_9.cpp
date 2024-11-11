#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using lli = long long int;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
using ulli = unsigned long long int;
using ui = unsigned int;
using Bit = bitset<30>;
const int maxBit = 30;
const int maxN = 3e5;
const int block = 600;
const int cBlocks = maxN / block;
const int C = 1e3;
const int maxM = 2e5;
const int maxl = 18;
const int inf = 0x3f3f3f3f;
const lli INF = 0x3f3f3f3f3f3f3f3f;
const char sp = ' ';
const char dl = '\n';
const int mod = 998244353;
int nxt[maxN * maxBit + 5][2], numNode;
vector<int> List[maxN * maxBit + 5];
lli f[maxBit][2];
void Insert(const Bit& a, const int& idx) {
  int cur = 0;
  for (int i = maxBit - 1; i >= 0; i--) {
    if (!nxt[cur][a[i]]) nxt[cur][a[i]] = ++numNode;
    cur = nxt[cur][a[i]];
    List[cur].push_back(idx);
  }
  return;
}
void dfs(int cur, int bit) {
  int l = nxt[cur][0];
  int r = nxt[cur][1];
  if (l) dfs(l, bit - 1);
  if (r) dfs(r, bit - 1);
  if (!cur) return;
  lli res = 0;
  int j = 0;
  for (int x : List[l]) {
    while (j < ((int)List[r].size()) && List[r][j] < x) j++;
    res += j;
  }
  f[bit][0] += res;
  f[bit][1] += 1ll * ((int)List[l].size()) * ((int)List[r].size()) - res;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test = 1;
  while (test--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      Insert(Bit(a[i]), i);
    }
    dfs(0, 29);
    lli res = 0, cnt = 0;
    for (int i = maxBit - 1; i >= 0; i--) {
      cnt += min(f[i][0], f[i][1]);
      if (f[i][1] < f[i][0]) res += (1 << i);
    }
    cout << cnt << ' ' << res << '\n';
  }
  return 0;
}
