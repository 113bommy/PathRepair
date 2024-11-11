#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
int n, k, a[maxn], ans[maxn], pos[maxn];
class Node {
 public:
  int l, r;
};
Node lis[maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> a[i + 1];
    pos[a[i + 1]] = i + 1;
    lis[i + 1].l = i;
    lis[i + 1].r = i + 2;
  }
  int team = 1;
  for (int i = n; i >= 1; i--) {
    int p = pos[i];
    if (ans[p] != 0) continue;
    ans[p] = team;
    for (int(j) = 0; (j) < (k); (j)++) {
      int el = lis[p].r;
      if (el != n + 1) {
        ans[el] = team;
        lis[lis[el].l].r = lis[el].r;
        lis[lis[el].r].l = lis[el].l;
      } else
        break;
    }
    for (int(j) = 0; (j) < (k); (j)++) {
      int el = lis[p].l;
      if (el != 0) {
        ans[el] = team;
        lis[lis[el].l].r = lis[el].r;
        lis[lis[el].r].l = lis[el].l;
      } else
        break;
    }
    lis[lis[p].l].r = lis[p].r;
    lis[lis[p].r].l = lis[p].l;
    if (team == 1)
      team = 2;
    else
      team = 1;
  }
  for (int(i) = 0; (i) < (n); (i)++) cout << ans[i + 1];
  cout << endl;
}
