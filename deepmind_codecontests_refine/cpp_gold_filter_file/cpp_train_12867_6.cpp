#include <bits/stdc++.h>
using namespace std;
static const int INF = 0x7fffffff;
static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
template <typename T, typename U>
static void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T& x, U y) {
  if (x < y) x = y;
}
struct node {
  int val, sign, id;
};
bool cmp(const node& a, const node& b) {
  if (a.val == b.val)
    return a.sign < b.sign;
  else
    return a.val < b.val;
}
int main(int argc, char const* argv[]) {
  int n, x;
  cin >> n >> x;
  vector<int> du(n), ct(n);
  vector<node> vac(n * 2);
  for (int(i) = 0; (i) < (int)(n); ++(i)) {
    int l, r, c;
    cin >> l >> r >> c;
    du[i] = r - l + 1;
    ct[i] = c;
    vac[2 * i] = (node){l, -1, i};
    vac[2 * i + 1] = (node){r, 1, i};
  }
  sort(vac.begin(), vac.end(), cmp);
  int res = INF;
  vector<int> bc(x + 1, INF);
  for (const node& nd : vac) {
    int len = du[nd.id];
    if (len >= x) continue;
    if (nd.sign == -1) {
      if (bc[x - len] != INF) amin(res, bc[x - len] + ct[nd.id]);
    } else {
      amin(bc[len], ct[nd.id]);
    }
  }
  if (res == INF)
    cout << -1;
  else
    cout << res;
  return 0;
}
