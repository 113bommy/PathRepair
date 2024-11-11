#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
long long n, m, p, k;
long long v[1001][1001];
long long sl[1001];
long long sc[1001];
long long ans1[10010000], ans2[10010000];
void f1() {
  priority_queue<long long> q;
  int i;
  for (i = 1; i <= n; i++) q.push(sl[i]);
  ans1[0] = 0;
  long long now = 0;
  for (i = 1; i <= k; i++) {
    long long tmp = q.top();
    now += tmp;
    q.pop();
    q.push(tmp - 1LL * p * m);
    ans1[i] = now;
  }
}
void f2() {
  priority_queue<long long> q;
  int i;
  for (i = 1; i <= m; i++) {
    q.push(sc[i]);
  }
  ans2[0] = 0;
  long long now = 0;
  for (i = 1; i <= k; i++) {
    long long tmp = q.top();
    now += tmp;
    q.pop();
    q.push(tmp - 1LL * p * n);
    ans2[i] = now;
  }
}
int main() {
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> v[i][j];
      sl[i] += v[i][j];
      sc[j] += v[i][j];
    }
  f1();
  f2();
  long long ans = -1000000000000000000LL;
  int i;
  for (i = 0; i <= k; i++) {
    long long tmp = ans1[i] + ans2[k - i] - 1LL * i * (k - i) * p;
    if (tmp > ans) ans = tmp;
  }
  cout << ans << endl;
  return 0;
}
