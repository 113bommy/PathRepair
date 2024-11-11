#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
const int INF = 1e9 + 7;
int pos[maxn];
vector<int> p1, p2, t1, t2;
struct note {
  int t1, t2, t3;
};
struct node {
  int x, pos;
  bool operator<(const node t1) const { return x < t1.x; }
} a[maxn];
vector<note> ans;
int main() {
  int n, m;
  scanf("%d", &n);
  for (int q = 1; q <= n; q++) {
    scanf("%d", &a[q].x);
    a[q].pos = q;
  }
  for (int q = 1; q <= n; q++) scanf("%d", &pos[q]);
  sort(a + 1, a + 1 + n);
  sort(pos + 1, pos + 1 + n);
  int an = 0, f = 1;
  for (int q = 1; q <= n; q++) {
    if (a[q].x < pos[q]) {
      p1.push_back(q);
      t1.push_back(pos[q] - a[q].x);
      an += pos[q] - a[q].x;
    } else if (a[q].x > pos[q]) {
      p2.push_back(q);
      t2.push_back(a[q].x - pos[q]);
      an -= a[q].x - pos[q];
    }
    if (an < 0) {
      f = 0;
    }
  }
  if (an != 0) f = 0;
  if (f == 0) {
    puts("NO");
    return 0;
  }
  int l = 0;
  for (int q = 0; q < p1.size(); q++) {
    for (; l < p2.size(); l++) {
      if (t2[l] == 0) continue;
      if (t1[q] <= t2[l]) {
        ans.push_back(note{p1[q], p2[l], t1[q]});
        t2[l] -= t1[q];
        break;
      } else {
        ans.push_back(note{p1[q], p2[l], t2[l]});
        t1[q] -= t2[l];
      }
    }
  }
  printf("YES\n");
  printf("%d\n", ans.size());
  for (int q = 0; q < ans.size(); q++)
    printf("%d %d %d\n", a[ans[q].t1].pos, a[ans[q].t2].pos, ans[q].t3);
  return 0;
}
