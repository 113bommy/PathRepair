#include <bits/stdc++.h>
using namespace std;
struct cp {
  int pos;
  int val;
};
cp v1[110];
cp v2[110];
int n, cn1, cn2, i;
bool cmp1(cp a, cp b) { return a.pos < b.pos; }
bool cmp2(cp a, cp b) { return a.pos > b.pos; }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x < 0) {
      scanf("%d", &v1[++cn1].val);
      v1[cn1].pos = x;
    } else {
      scanf("%d", &v2[++cn2].val);
      v2[cn2].pos = x;
    }
  }
  sort(v1 + 1, v1 + cn1 + 1, cmp2);
  sort(v2 + 1, v2 + cn2 + 1, cmp1);
  int r = min(cn1, cn2);
  int s = 0;
  for (i = 1; i <= r; i++) {
    s += v1[i].val;
    s += v2[i].val;
  }
  int s1, s2;
  s1 = s;
  s2 = s;
  if (cn1 > r) s1 += v1[r + 1].val;
  if (cn2 > r) s2 += v2[r + 1].val;
  printf("%d", max(s1, s2));
  return 0;
}
