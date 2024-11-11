#include <bits/stdc++.h>
using namespace std;
const int MAX = 2147483647;
int n, ans[1010], cnt, mid, nl, nr, num[1010];
struct hehe {
  int l, r;
} e[1010];
int cmp(const hehe& a, const hehe& b) {
  if (a.l == b.l)
    return a.r < b.r;
  else
    return a.l < b.l;
}
bool check(int x) {
  int sr = e[1].r;
  cnt = 1;
  ans[cnt] = 1;
  for (int i = 2; i <= n; i++) {
    if (e[i].r < e[ans[cnt]].r) {
      ans[cnt] = i;
    } else if (e[i].l > e[ans[cnt]].r)
      cnt++, ans[cnt] = i;
  }
  if (cnt <= x) {
    for (int i = 1; i <= cnt; i++) num[i] = ans[i];
    return 1;
  } else
    return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &e[i].l, &e[i].r);
    if (e[i].l > e[i].r) swap(e[i].l, e[i].r);
  }
  sort(e + 1, e + n + 1, cmp);
  nl = 1, nr = n;
  num[1] = 1;
  cnt = 1;
  while (nl < nr) {
    mid = (nl + nr) / 2;
    if (check(mid))
      nr = mid;
    else
      nl = mid + 1;
  }
  cout << nr << endl;
  for (int i = 1; i <= cnt; i++) cout << e[num[i]].r << " ";
  return 0;
}
