#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
map<long long, map<int, long long>> a;
long long dp[100];
int x[10] = {0, 2, 1, 4, 3, 6, 5};
map<long long, int> color;
int main() {
  int kk;
  cin >> kk;
  dp[1] = 1;
  for (int i = 2; i <= kk; i++) {
    dp[i] = dp[i - 1] * dp[i - 1] % p * 16 % p;
  }
  int n;
  cin >> n;
  priority_queue<long long, vector<long long>, less<long long>> q;
  for (int i = 1; i <= n; i++) {
    int id;
    string s;
    cin >> id >> s;
    if (s == "white") color[id] = 1;
    if (s == "yellow") color[id] = 2;
    if (s == "green") color[id] = 3;
    if (s == "blue") color[id] = 4;
    if (s == "red") color[id] = 5;
    if (s == "orange") color[id] = 6;
    q.push(id);
    int pos = 0;
    for (long long j = id; j; j >>= 1) pos++;
    a[id][color[id]] = dp[kk - pos + 1];
  }
  while (!q.empty()) {
    long long id = q.top();
    q.pop();
    if (id == 1) {
      long long ans = 0;
      for (int i = 1; i <= 6; i++) ans += a[1][i];
      ans %= p;
      cout << ans << endl;
      return 0;
    }
    if (color[id / 2]) {
      for (int i = 1; i <= 6; i++) {
        a[id / 2][i] = 0;
      }
    }
    if (!q.empty() && q.top() == id / 2 * 2) {
      long long x1 = id, x2 = id - 1;
      q.pop();
      for (int i = 1; i <= 6; i++) {
        if (color[id / 2] && i != color[id / 2]) continue;
        for (int j = 1; j <= 6; j++) {
          if (i == j || x[i] == j) continue;
          for (int k = 1; k <= 6; k++) {
            if (i == k || x[i] == k) continue;
            a[id / 2][i] = (a[id / 2][i] + a[x1][j] * a[x2][k] % p) % p;
          }
        }
      }
    } else {
      int pos = 0;
      for (long long i = id; i; i >>= 1) pos++;
      for (int i = 1; i <= 6; i++) {
        if (color[id / 2] && i != color[id / 2]) continue;
        for (int j = 1; j <= 6; j++) {
          if (i == j || x[i] == j) continue;
          for (int k = 1; k <= 6; k++) {
            if (i == k || x[i] == k) continue;
            a[id / 2][i] = (a[id / 2][i] + a[id][j] * dp[kk - pos + 1] % p) % p;
          }
        }
      }
    }
    if (!color[id / 2]) q.push(id / 2);
  }
}
