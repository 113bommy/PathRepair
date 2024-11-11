#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const long long mod = 1e9 + 7;
int n, p, q, h;
struct node {
  int x, y, z, id;
} a[N], b[N];
bool cmp1(node a, node b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
bool cmp2(node a, node b) { return a.z > b.z; }
long long calc(long long x, long long y) {
  return (long long)p * q - (p - x) * (q - y);
}
int st[N];
long long sum[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p >> q >> h;
  for (int i = (1); i < (n + 1); i++) cin >> a[i].x >> a[i].y >> a[i].z;
  sort(a + 1, a + n + 1, cmp1);
  int top = 0;
  for (int i = (1); i < (n + 1); i++) {
    while (top && a[st[top]].y <= a[i].y) top--;
    st[++top] = i;
  }
  long long un = 0, ans = 0;
  for (int i = (1); i < (top + 1); i++) {
    b[i] = a[st[i]];
  }
  for (int i = (1); i < (top + 1); i++) {
    un += (long long)(a[st[i]].x - a[st[i - 1]].x) * a[st[i]].y;
    sum[i] = un;
  }
  sort(a + 1, a + n + 1, cmp2);
  int px = 0, py = 0;
  int j = 1;
  int l = 1, r = top;
  for (int i = h; i >= 1; --i) {
    while (j <= n && a[j].z >= i) {
      px = max(px, a[j].x);
      py = max(py, a[j].y);
      j++;
    }
    while (l <= top && b[l].x <= px) l++;
    while (r >= 1 && b[r].y <= py) r--;
    if (px == 0 && py == 0)
      ans += un;
    else {
      long long res = 0;
      if (l <= r) {
        res = (sum[r] - sum[l - 1]) - ((long long)py * (b[r].x - px) +
                                       (long long)b[l].y * (px - b[l - 1].x));
      }
      ans += calc(px, py) + res;
    }
  }
  ans = (long long)p * q * h - ans;
  cout << ans << endl;
  return 0;
}
