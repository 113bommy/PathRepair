#include <bits/stdc++.h>
using namespace std;
const int M = 1200000;
const int inf = 0x3f3f3f3f;
int n, m, k;
bool dp[1 << 16][2222] = {0};
int b[17] = {0};
int a[20];
void add(int x) {
  for (int i = (0); i <= (n - 1); ++i) b[i] += ((x >> i) & 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  int sum = 0;
  for (int i = (0); i <= (n - 1); ++i) {
    cin >> a[i];
    sum += a[i];
  }
  dp[0][0] = 1;
  m = (1 << n);
  for (int i = (0); i <= (m - 1); ++i) {
    for (int z = (sum); z >= (1); --z) {
      if (z % k == 0) {
        dp[i][z / k] |= dp[i][z];
      }
    }
    for (int j = (0); j <= (n - 1); ++j) {
      if ((i >> j) & 1) continue;
      int to = (i | (1 << j));
      for (int z = (0); z <= (sum - a[j]); ++z) {
        dp[to][z + a[j]] |= dp[i][z];
      }
    }
  }
  if (dp[m - 1][1]) {
    cout << "YES" << endl;
    int u = m - 1, v = 1;
    while (u + v) {
      for (int i = (0); i <= (n - 1); ++i) {
        if (((u >> i) & 1) && v >= a[i] && dp[u ^ (1 << i)][v - a[i]]) {
          u ^= (1 << i);
          v -= a[i];
          break;
        }
      }
      if (v * k <= sum && dp[u][v * k]) {
        add(u);
        v *= k;
      }
    }
    priority_queue<pair<short, short> > q;
    for (int i = (0); i <= (n - 1); ++i) q.push({b[i], a[i]});
    for (int i = (0); i <= (n - 2); ++i) {
      pair<short, short> p1 = q.top();
      q.pop();
      pair<short, short> p2 = q.top();
      q.pop();
      cout << p1.second << ' ' << p2.second << endl;
      int tmp = p1.second + p2.second;
      int c = 0;
      while (tmp % k == 0) {
        ++c;
        tmp /= k;
      }
      int nb = p1.first - c;
      q.push({nb, tmp});
    }
  } else
    cout << "NO" << endl;
  return 0;
}
