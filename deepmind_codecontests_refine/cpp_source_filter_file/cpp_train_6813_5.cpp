#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
long long t[1001][1001];
long long o[1001];
long long s[1001];
long long sornyer[1000001];
long long oszlopnyer[1000001];
int main() {
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> t[i][j];
  }
  for (int i = 1; i <= n; i++) {
    s[i] = 0;
    for (int j = 1; j <= m; j++) {
      s[i] += t[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    o[i] = 0;
    for (int j = 1; j <= n; j++) {
      o[i] += t[j][i];
    }
  }
  long long mo = -1;
  sornyer[0] = 0;
  priority_queue<long long> q;
  for (int i = 1; i <= n; i++) q.push(s[i]);
  for (int i = 1; i <= k; i++) {
    sornyer[i] = sornyer[i - 1] + q.top();
    long long x = q.top();
    q.pop();
    q.push(x - n * p);
  }
  oszlopnyer[0] = 0;
  priority_queue<long long> r;
  for (int i = 1; i <= m; i++) r.push(o[i]);
  for (int i = 1; i <= k; i++) {
    oszlopnyer[i] = oszlopnyer[i - 1] + r.top();
    long long x = r.top();
    r.pop();
    r.push(x - m * p);
  }
  mo = oszlopnyer[k];
  for (int i = 1; i <= k; i++) {
    mo = max(mo, sornyer[i] + oszlopnyer[k - i] - (long long)(k - i) * i * p);
  }
  cout << mo;
  return 0;
}
