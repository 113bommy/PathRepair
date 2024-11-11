#include <bits/stdc++.h>
using namespace std;
struct node {
  long long m, s;
};
const int maxn = 100000 + 10;
node p[maxn];
long long sum[maxn];
int n;
long long d;
bool cmp(const node &a, const node &b) { return a.m < b.m; }
int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> p[i].m >> p[i].s;
  sort(p + 1, p + 1 + n, cmp);
  p[n + 1].m = 1000000000 + 10;
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i].s;
  long long ans = -1;
  for (int i = 1; i <= n; i++) {
    int l = i + 1;
    int r = n + 1;
    int pos = i;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (p[mid].m > p[i].m + d) {
        pos = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (sum[pos - 1] - sum[i - 1] > ans) ans = sum[pos - 1] - sum[i - 1];
  }
  cout << ans << endl;
  return 0;
}
