#include <bits/stdc++.h>
using namespace std;
const unsigned long long MAX_UINT64 = 18446744073709551615ULL;
const unsigned long MAX_UINT32 = 4294967296LL;
const unsigned int MAX_UINT16 = 65535;
const long long MAX_INT64 = 9223372036854775807LL;
const long MAX_INT32 = 2147483647LL;
const int MAX_INT16 = 32768;
const int MAXN = 123456 + 8;
int n, m, r, x, y, z, h, sum = 0;
int L[MAXN], C[MAXN], P[MAXN];
bitset<MAXN> attacked, mark;
vector<int> paths[MAXN];
pair<int, int> ans;
inline bool pre_create_level(int node, int level) {
  if (attacked[node]) ans = max(make_pair(level, -node), ans);
  mark[node] = 1;
  bool is_attack = attacked[node];
  for (int i = 0; i < paths[node].size(); i++) {
    int next = paths[node][i];
    if (mark[next]) continue;
    bool tmp = pre_create_level(next, level + 1);
    if (tmp) {
      sum++;
      is_attack = true;
    }
  }
  return is_attack;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &x, &y);
    paths[x].push_back(y);
    paths[y].push_back(x);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &r);
    attacked[r] = 1;
  }
  ans = make_pair(0, -1e9);
  h = pre_create_level(r, 0);
  pair<int, int> res = ans;
  ans = make_pair(0, -1e9);
  mark = 0;
  sum = 0;
  h = pre_create_level(-res.second, 0);
  printf("%d\n%d\n", -max(res.second, ans.second), sum * 2 - res.first);
  return 0;
}
