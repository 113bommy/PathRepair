#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10, MAXM = 2e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
const int inv2 = 5e8 + 4;
int n, a[MAXN], b[MAXN], m, k, s;
struct Node {
  int type, val, id;
  bool operator<(const Node &rhs) const { return val < rhs.val; }
};
vector<Node> A, B;
long long suma[MAXN], sumb[MAXN];
int ansq;
bool check(int v) {
  for (int i = 0; i <= k; i++) {
    if (i > ((int)A.size()) || (k - i) > ((int)B.size())) continue;
    if (suma[i] * a[v] + sumb[k - i] * b[v] <= s) {
      ansq = i;
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 2; i <= n; i++)
    a[i] = min(a[i], a[i - 1]), b[i] = min(b[i], b[i - 1]);
  for (int i = 1; i <= m; i++) {
    Node tmp;
    scanf("%d%d", &tmp.type, &tmp.val);
    tmp.id = i;
    if (tmp.type == 1)
      A.push_back(tmp);
    else
      B.push_back(tmp);
  }
  sort((A).begin(), (A).end());
  sort((B).begin(), (B).end());
  for (int i = 1; i <= ((int)A.size()); i++)
    suma[i] = A[i - 1].val + suma[i - 1];
  for (int i = 1; i <= ((int)B.size()); i++)
    sumb[i] = B[i - 1].val + sumb[i - 1];
  int l = 1, r = m, ans = m + 1, ansp;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid, ansp = ansq;
    else
      l = mid + 1;
  }
  if (ans == m + 1) return puts("-1"), 0;
  printf("%d\n", ans);
  int aa = min_element(a + 1, a + ans + 1) - a,
      bb = min_element(b + 1, b + ans + 1) - b;
  for (int i = 0; i < ansp; i++) printf("%d %d\n", A[i].id, aa);
  for (int i = 0; i < k - ansp; i++) printf("%d %d\n", B[i].id, bb);
  return 0;
}
