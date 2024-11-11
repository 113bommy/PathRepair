#include <bits/stdc++.h>
using namespace std;
int n, q;
const int N = (1 << 18) + 2, MOD = 1000000007LL;
struct segmentTree {
  long long tree[N];
  void update(int qs, int qe, long long val, int ni = 0, int ns = 0,
              int ne = n - 1) {
    if (qs > ne || qe < ns) return;
    if (ns >= qs && ne <= qe) {
      tree[ni] = max(tree[ni], val);
      return;
    }
    int lf = 2 * ni + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    update(qs, qe, val, lf, ns, mid);
    update(qs, qe, val, rt, mid + 1, ne);
    tree[ni] = max(tree[lf], tree[rt]);
  }
  long long query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
    if (qs > ne || qe < ns) return 0;
    if (ns >= qs && ne <= qe) {
      return tree[ni];
    }
    int lf = 2 * ni + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
    long long a = query(qs, qe, lf, ns, mid),
              b = query(qs, qe, rt, mid + 1, ne);
    return max(a, b);
  }
};
segmentTree a;
const double PI = acos(-1);
int main() {
  scanf("%d", &n);
  vector<pair<long long, int>> arr(n);
  for (int i = 0; i < n; i++) {
    long long r, h;
    scanf("%lld%lld", &r, &h);
    arr[i].first = r * r * h;
    arr[i].second = -i;
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
    int idx = arr[i].second;
    long long ansWithoutMe = a.query(0, idx);
    a.update(idx, idx, ansWithoutMe + arr[i].first);
  }
  printf("%.7lf\n", PI * a.query(0, n - 1));
  return 0;
}
