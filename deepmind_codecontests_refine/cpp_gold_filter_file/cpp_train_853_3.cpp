#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n;
struct node {
  int x, y, z, cnt;
} no[MAXN], t[MAXN];
bool cmp1(node a, node b) { return a.z < b.z; }
bool cmp2(node a, node b) {
  if (a.x == b.x) {
    return a.z < b.z;
  } else {
    return a.x > b.x;
  }
}
long long bt[MAXN];
void ins(int pos, int val) {
  while (pos <= n) {
    bt[pos] += val;
    pos += pos & -pos;
  }
}
long long get(int pos) {
  long long res = 0;
  while (pos) {
    res += bt[pos];
    pos -= pos & -pos;
  }
  return res;
}
void cdq(int l, int r) {
  if (l == r) {
    return;
  }
  int m = (l + r) >> 1;
  cdq(l, m);
  cdq(m + 1, r);
  int pl = l, pr = m + 1, pos = l;
  while (pl <= m) {
    while (pr <= r && no[pl].y <= no[pr].y) {
      no[pr].cnt += get(n) - get(no[pr].z);
      t[pos++] = no[pr++];
    }
    ins(no[pl].z, 1);
    t[pos++] = no[pl++];
  }
  while (pr <= r) {
    no[pr].cnt += get(n) - get(no[pr].z);
    t[pos++] = no[pr++];
  }
  for (int i = l; i <= m; i++) {
    ins(no[i].z, -1);
  }
  for (int i = l; i <= r; i++) {
    no[i] = t[i];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &no[i].x);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &no[i].y);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &no[i].z);
  }
  sort(no + 1, no + 1 + n, cmp1);
  int t = -1;
  for (int i = 1; i <= n; i++) {
    if (t == no[i].z) {
      no[i].z = no[i - 1].z;
    } else {
      t = no[i].z;
      no[i].z = i;
    }
  }
  sort(no + 1, no + 1 + n, cmp2);
  cdq(1, n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (no[i].cnt) {
      ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
