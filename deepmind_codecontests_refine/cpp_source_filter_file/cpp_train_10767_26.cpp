#include <bits/stdc++.h>
using namespace std;
const int maxn = 111111, inf = ~0U >> 1;
const long long mod = 1000000007ll;
int n, m;
long long A[maxn], d[maxn], C[maxn][101];
vector<pair<int, int> > ins[maxn], del[maxn];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%lld", A + i);
  for (int i = 0; i < m; i++) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l;
    ins[l].push_back(make_pair(0, k));
    del[r].push_back(make_pair(r - l, k));
  }
  memset(d, (0), sizeof(d));
  for (int i = 0; i < n + 1; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= 100 && j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 0; i < n; i++) {
    for (__typeof(ins[i].begin()) it = ins[i].begin(); it != ins[i].end();
         it++) {
      int x = it->first, y = it->second;
      for (int j = 0; j < y + 1; j++) d[j] = (d[j] + C[x + y][y - j]) % mod;
    }
    for (__typeof(del[i].begin()) it = del[i].begin(); it != del[i].end();
         it++) {
      int x = it->first, y = it->second;
      for (int j = 0; j < y + 1; j++)
        d[j] = (d[j] + mod - C[x + y][y - j]) % mod;
    }
    printf("%lld%c", (A[i] + d[0] + mod) % mod, (i == n - 1 ? '\n' : ' '));
    for (int j = 0; j < 101; j++) d[j] = (d[j] + d[j + 1]) % mod;
  }
}
