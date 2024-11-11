#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double pi = acos(-1.0);
int n;
long long A, cf, cm;
long long m;
long long pre[N];
int ans[N];
struct node {
  int id;
  long long w;
  bool operator<(const node& temp) const {
    return w == temp.w ? id < temp.id : w < temp.w;
  }
} p[N];
int a[N];
int res[N];
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &p[i].w);
    p[i].id = i;
    res[i] = p[i].w;
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++) {
    a[i] = p[i].w;
    pre[i] = pre[i - 1] + a[i];
  }
  int val = 0, besti = -1;
  long long ans = 0;
  for (int i = n; i >= 0; i--) {
    long long money = m - ((long long)(n - i) * A - (pre[n] - pre[i]));
    if (money < 0) break;
    int L = 0, R = A;
    int Ans = 0;
    while (L <= R) {
      int mid = L + R >> 1;
      int t = upper_bound(a + 1, a + 1 + i, mid) - a - 1;
      if (money - (1LL * mid * t - pre[t]) >= 0) {
        Ans = mid;
        L = mid + 1;
      } else
        R = mid - 1;
    }
    if (1LL * (n - i) * cf + (long long)Ans * cm > ans) {
      ans = 1LL * (n - i) * cf + (long long)Ans * cm;
      val = Ans;
      besti = i;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++)
    if (res[i] < val) res[i] = val;
  for (int i = besti + 1; i <= n; i++) res[p[i].id] = A;
  for (int i = 1; i <= n; i++) printf("%d%c", res[i], i == n ? '\n' : ' ');
  return 0;
}
