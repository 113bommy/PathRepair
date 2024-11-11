#include <bits/stdc++.h>
using namespace std;
int n, m, dem;
long long a[200010], b[200010], p[2 * 200010];
pair<long long, long long> kq = make_pair(-1e9, 1e9);
void nhap() {
  cin >> n;
  dem = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[++dem] = a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    p[++dem] = b[i];
  }
}
void chuanbi() {
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  sort(p + 1, p + dem + 1);
  p[0] = 0;
  p[dem + 1] = p[dem++] + 1;
}
void xuli() {
  for (int i = 0; i <= dem; i++) {
    long long x = p[i];
    int vt1 = upper_bound(a + 1, a + n + 1, x) - a;
    int vt2 = upper_bound(b + 1, b + m + 1, x) - b;
    long long sum1 = max(0, vt1 - 1) * 2 + max(0, n - vt1 + 1) * 3;
    long long sum2 = max(0, vt2 - 1) * 2 + max(0, m - vt2 + 1) * 3;
    if (sum1 - sum2 > kq.first - kq.second)
      kq = make_pair(sum1, sum2);
    else if (sum1 - sum2 == kq.first - kq.second && sum1 > kq.first)
      kq = make_pair(sum1, sum2);
  }
  cout << kq.first << ":" << kq.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  nhap();
  chuanbi();
  xuli();
}
