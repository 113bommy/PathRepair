#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> p;
priority_queue<long long> q;
long long a[1005][1005];
long long n, m, k, r;
long long ngang[1005 * 1005];
long long doc[1005 * 1005];
void nhap() {
  cin >> n >> m >> k >> r;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
}
void chuanbi() {
  long long x;
  for (int i = 1; i <= n; i++) {
    x = 0;
    for (int j = 1; j <= m; j++) x = x + a[i][j];
    p.push(x);
  }
  for (int j = 1; j <= m; j++) {
    x = 0;
    for (int i = 1; i <= n; i++) x = x + a[i][j];
    q.push(x);
  }
}
void xuli() {
  long long s = 0;
  long long demd = 0;
  long long demn = 0;
  for (int i = 1; i <= k; i++) {
    long long u = p.top();
    p.pop();
    ngang[i] = ngang[i - 1] + u;
    p.push(u - m * r);
  }
  for (int j = 1; j <= k; j++) {
    long long u = q.top();
    q.pop();
    doc[j] = doc[j - 1] + u;
    q.push(u - n * r);
  }
  long long kq = -1000000000003;
  for (int i = 0; i <= k; i++)
    kq = max(kq, doc[i] + ngang[k - i] - r * i * (k - i));
  cout << kq;
}
int main() {
  nhap();
  chuanbi();
  xuli();
}
