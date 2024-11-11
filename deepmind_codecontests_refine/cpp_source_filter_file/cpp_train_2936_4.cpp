#include <bits/stdc++.h>
using namespace std;
const int MX = 2002, BS = 1 << 16, MOD = 1e9 + 7;
int n, k, a[16], b[16];
bitset<MX> dp[BS];
void reverseDP(int bs, int x) {
  if (x != 0 && x * k < MX && dp[bs][x * k]) {
    reverseDP(bs, x * k);
    for (int i = int(0); i < int(n); i++)
      if (bs & (1 << i)) {
        b[i]++;
      }
  } else {
    for (int i = int(0); i < int(n); i++)
      if ((bs & (1 << i)) && (x - a[i] >= 0) && dp[bs ^ (1 << i)][x - a[i]]) {
        reverseDP(bs ^ (1 << i), x - a[i]);
        return;
      }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = int(0); i < int(n); i++) cin >> a[i];
  int mxBS = (1 << n);
  for (int i = int(0); i < int(mxBS); i++) dp[i].reset();
  dp[0][0] = 1;
  for (int bs = int(1); bs < int(mxBS); bs++) {
    for (int i = int(0); i < int(n); i++)
      if ((bs & (1 << i))) dp[bs] |= (dp[bs ^ (1 << i)] << a[i]);
    for (int i = int((MX - 1) / k - 1); i >= int(1); i--)
      if (dp[bs][i * k]) dp[bs][i] = 1;
  }
  if (dp[(1 << n) - 1][1]) {
    cout << "YES" << endl;
    for (int i = int(0); i < int(n); i++) b[i] = 0;
    reverseDP((1 << n) - 1, 1);
    priority_queue<pair<int, int> > pq;
    for (int i = int(0); i < int(n); i++) pq.push({b[i], a[i]});
    while (pq.size() >= 2) {
      pair<int, int> p1 = pq.top();
      pq.pop();
      pair<int, int> p2 = pq.top();
      pq.pop();
      int nb = p1.first;
      int na = p1.second + p2.second;
      cout << p1.second << " " << p2.second << endl;
      while (na % k == 0) {
        na /= k;
        nb--;
      }
      pq.push({nb, na});
    }
  } else {
    cout << "NO" << endl;
  }
}
