#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
signed main() {
  ios_base::sync_with_stdio(0);
  long long n, m, k;
  cin >> n >> m >> k;
  n++;
  vector<vector<long long>> mas(m, vector<long long>(4));
  for (long long i = 0; i < m; i++) {
    cin >> mas[i][0] >> mas[i][1] >> mas[i][2] >> mas[i][3];
  }
  sort(mas.begin(), mas.end());
  long long time = 1e6 + 10;
  vector<long long> ans1(time, INF);
  vector<long long> ans2(time, INF);
  vector<long long> pep(n, INF);
  long long koll = 0;
  long long ans = 0;
  long long i = 0;
  for (long long j = 0; j < time; j++) {
    while (i < n && mas[i][0] == j) {
      long long t, v, u, st;
      t = mas[i][0];
      v = mas[i][1];
      u = mas[i][2];
      st = mas[i][3];
      if (u == 0) {
        if (pep[v] == INF) {
          pep[v] = st;
          koll++;
          ans += st;
        } else if (pep[v] > st) {
          ans -= pep[v];
          pep[v] = st;
          ans += st;
        }
      }
      i++;
    }
    if (koll == n - 1) {
      ans1[j] = ans;
    }
  }
  koll = 0;
  ans = 0;
  for (long long i = 0; i < n; i++) pep[i] = INF;
  reverse(mas.begin(), mas.end());
  i = 0;
  for (long long j = time - 1; j >= 0; j--) {
    while (i < n && mas[i][0] == j) {
      long long t, v, u, st;
      t = mas[i][0];
      v = mas[i][1];
      u = mas[i][2];
      st = mas[i][3];
      if (v == 0) {
        if (pep[u] == INF) {
          pep[u] = st;
          koll++;
          ans += st;
        } else if (pep[u] > st) {
          ans -= pep[u];
          pep[u] = st;
          ans += st;
        }
      }
      i++;
    }
    if (koll == n - 1) {
      ans2[j] = ans;
    }
  }
  ans = -1;
  for (long long i = 0; i < time; i++) {
    if (i + k + 1 >= time) continue;
    if (ans1[i] == INF || ans2[i + k + 1] == INF) continue;
    if (ans == -1)
      ans = ans1[i] + ans2[i + k + 1];
    else
      ans = min(ans, ans1[i] + ans2[i + k + 1]);
  }
  cout << ans;
  return 0;
}
