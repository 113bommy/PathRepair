#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200005;
LL f[N];
int p[N];
int res[N];
struct Node {
  LL val;
  int id;
  bool operator<(const Node& rhs) const {
    if (val == rhs.val) return id < rhs.id;
    return val < rhs.val;
  }
} a[N];
int main() {
  memset(f, 0x3f, sizeof f);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i].val);
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  f[0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 3; j <= 5 && i + j <= n; ++j) {
      LL diff = a[i + j].val - a[i + 1].val;
      if (i + j <= n && f[i + j] > f[i] + diff) {
        f[i + j] = f[i] + diff;
        p[i + j] = i;
      }
    }
  }
  int cur = n;
  int cnt = 0;
  while (cur != 0) {
    for (int i = cur - 1; i >= p[cur]; --i) {
      res[a[i].id] = cnt;
    }
    ++cnt;
    cur = p[cur];
  }
  cout << f[n] << " " << cnt << endl;
  for (int i = 1; i <= n; ++i) printf("%d ", res[i] + 1);
  return 0;
}
