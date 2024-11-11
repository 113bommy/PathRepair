#include <bits/stdc++.h>
using namespace std;
const int loveisblue = 486;
const int maxn = 300086;
const int maxm = 100086;
const int inf = 0x3f3f3f3f;
const long long Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);
int num[maxn], pos[maxn];
int bit[maxn];
int lowbit(int x) { return x & -x; }
int query(int pos) {
  int ans = 0;
  while (pos) {
    ans += bit[pos];
    pos -= lowbit(pos);
  }
  return ans;
}
void update(int pos, int val) {
  while (pos < maxn) {
    bit[pos] += val;
    pos += lowbit(pos);
  }
}
int main() {
  ios::sync_with_stdio(true);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    pos[num[i]] = i;
  }
  for (int i = 1; i < n; i++) {
    if (pos[i] > pos[i + 1]) {
      update(i, 1);
    }
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", query(r - 1) - query(l - 1) + 1);
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      swap(num[x], num[y]);
      x = num[x];
      y = num[y];
      int t1 = pos[x];
      int t2 = pos[y];
      if (t1 > t2) {
        swap(x, y);
        swap(t1, t2);
      }
      if (pos[x + 1] >= pos[x] && pos[x + 1] <= pos[y]) {
        update(x, 1);
      }
      if (x > 1 && x - 1 != y && pos[x - 1] >= pos[x] && pos[x - 1] <= pos[y]) {
        update(x - 1, -1);
      }
      if (pos[y + 1] >= pos[x] && pos[y + 1] <= pos[y]) {
        update(y, -1);
      }
      if (y > 1 && y - 1 != x && pos[y - 1] >= pos[x] && pos[y - 1] <= pos[y]) {
        update(y - 1, 1);
      }
      swap(pos[x], pos[y]);
    }
  }
  return 0;
}
