#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, idx;
  bool operator<(const node &a) const { return val < a.val; }
} a[200005];
int n;
long long sum[200005];
vector<int> ver;
int my_upper_bound(int x) {
  int L = 1, R = n - 1, mid, ans = R;
  while (L <= R) {
    mid = (L + R) >> 1;
    if (a[mid].val > x) {
      ans = mid;
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return ans;
}
int my_lower_bound(int x) {
  int L = 1, R = n - 1, mid, ans = R;
  while (L <= R) {
    mid = (L + R) >> 1;
    if (a[mid].val >= x) {
      ans = mid;
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  return ans;
}
void solve() {
  for (register int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i].val;
  }
  long long t = sum[n - 1] - a[n].val;
  if (t > 0 && t <= 1000000) {
    int t2 = my_upper_bound(t);
    int t1 = my_lower_bound(t);
    for (register int i = t1; i <= t2 - 1; i++) {
      ver.push_back(a[i].idx);
    }
  }
  if (a[n - 1].val == sum[n - 2]) ver.push_back(a[n].idx);
  printf("%d\n", ver.size());
  for (int i = 0; i < ver.size(); i++) {
    printf("%d%c", ver[i], i == ver.size() - 1 ? '\n' : ' ');
  }
}
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    a[i].idx = i;
  }
  sort(a + 1, a + 1 + n);
  if (n > 2)
    solve();
  else
    puts("0");
  return 0;
}
