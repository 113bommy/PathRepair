#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n, x, A, B;
long long m;
int a[MAX_N];
pair<long long, long long> b[MAX_N];
long long pre[MAX_N];
long long second = -1, M_cnt, m_num;
int main() {
  cin >> n >> x >> A >> B >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = {a[i], i};
  }
  sort(b + 1, b + 1 + n);
  b[n + 1] = {x, n + 1};
  for (int i = 1; i <= n; i++)
    pre[i] = pre[i - 1] + (i - 1) * (b[i].first - b[i - 1].first);
  for (int i = n + 1; i >= 1; i--) {
    m -= x - b[i].first;
    if (m < 0) break;
    b[i].first = x;
    int r = (upper_bound(pre + 1, pre + 1 + n, m) - pre) - 1;
    int min_x =
        r == 0 ? b[1].first : min(b[r].first + (m - pre[r]) / r, 1ll * x);
    long long score = 1ll * A * (n + 1 - i) + 1ll * B * min_x;
    if (second < score) {
      second = score;
      M_cnt = i;
      m_num = min_x;
    }
  }
  for (int i = M_cnt; i <= n; i++) a[b[i].second] = x;
  for (int i = 1; i <= n; i++)
    if (a[i] < m_num) a[i] = m_num;
  cout << second << '\n';
  for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
  return 0;
}
