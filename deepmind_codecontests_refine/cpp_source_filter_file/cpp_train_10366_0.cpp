#include <bits/stdc++.h>
using namespace std;
struct query {
  int n;
  vector<bool> mask;
  vector<int> ans;
  query(const vector<bool>& m) : n(m.size()), mask(m) {
    vector<int> q;
    for (int i = 1, __R = n; i <= __R; i++)
      if (mask[i]) q.push_back(i);
    int k = q.size();
    if (!k) return;
    printf("%d\n", k);
    for (int i = 0, __R = k - 1; i <= __R; i++) {
      if (i > 0) printf(" ");
      printf("%d", q[i]);
    }
    printf("\n");
    fflush(stdout);
    ans.push_back(0);
    for (int i = 1, __R = n; i <= __R; i++) {
      int x;
      scanf("%d", &(x));
      ans.push_back(x);
    }
  }
  int row(int i) const {
    if (ans.size() && !mask[i]) return ans[i];
    return 0x3f3f3f3f3f3f3f3fLL;
  }
};
vector<query> Q;
void fill(vector<bool>& buf, int l, int r, int div) {
  if (r < l) return;
  int n = r - l + 1;
  int n2 = n >> 1, N2 = (n + 1) >> 1;
  if (!div)
    for (int i = l + n2, __R = r; i <= __R; i++) buf[i] = true;
  else {
    fill(buf, l, l + n2 - 1, div - 1);
    fill(buf, l + n2, r, div - 1);
  }
}
int main() {
  int n;
  scanf("%d", &(n));
  for (int div = 0, __R = 9; div <= __R; div++) {
    vector<bool> q(n + 1, false);
    fill(q, 1, n, div);
    Q.emplace_back(q);
    for (int i = 1, __R = n; i <= __R; i++) q[i] = !q[i];
    Q.emplace_back(q);
  }
  printf("-1\n");
  for (int i = 1, __R = n; i <= __R; i++) {
    int ans = 0x3f3f3f3f3f3f3f3fLL;
    for (auto& q : Q) ans = min(ans, q.row(i));
    printf("%d\n", ans);
  }
  fflush(stdout);
  return 0;
}
