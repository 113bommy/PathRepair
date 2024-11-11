#include <bits/stdc++.h>
using namespace std;
struct node {
  long long opt;
  int in;
  bool operator<(const node &b) const { return opt > b.opt; }
};
priority_queue<node> q;
long long n, m, k, p;
long long he[120001], ai[120001];
long long op[120001];
bool check(long long mid) {
  for (int i = 1; i <= n; i++) {
    op[i] = mid;
    if (op[i] - m * ai[i] < 0) q.push((node){mid / ai[i], i});
  }
  int cnt = 0;
  for (; cnt <= m * k; cnt++) {
    if (q.empty()) break;
    node tmp = q.top();
    q.pop();
    if (tmp.opt <= cnt / k) return false;
    op[tmp.in] += p;
    if (op[tmp.in] - m * ai[tmp.in] < 0)
      q.push((node){op[tmp.in] / ai[tmp.in], tmp.in});
  }
  if (cnt > m * k) return false;
  long long tmp;
  for (int i = 1; i <= n; i++) {
    tmp = ai[i] * m + he[i] - op[i];
    if (tmp > 0) cnt += (tmp / p + (long long)(tmp % p != 0));
    if (cnt > m * k) return false;
  }
  return true;
}
int main() {
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) cin >> he[i] >> ai[i];
  long long L = 1, R = 1e15;
  long long mid;
  long long ans = R;
  while (L != R) {
    mid = (L + R) >> 1;
    if (check(mid))
      ans = mid, R = mid;
    else
      L = mid + 1;
    while (!q.empty()) q.pop();
  }
  cout << ans;
}
