#include <bits/stdc++.h>
using namespace std;
long long sumr[2000], sumc[2000];
long long r[1000011], c[1000011];
int main() {
  int n, m, k, p;
  cin >> n >> m >> k >> p;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      sumr[i] += x;
      sumc[j] += x;
    }
  priority_queue<long long> R, C;
  for (int i = 0; i < n; i++) {
    R.push(sumr[i]);
  }
  for (int j = 0; j < m; j++) {
    C.push(sumc[j]);
  }
  for (int i = 0; i < k; i++) {
    long long now = R.top();
    r[i + 1] = now + r[i];
    now -= m * p;
    R.pop();
    R.push(now);
    now = C.top();
    c[i + 1] += now + c[i];
    now -= n * p;
    C.pop();
    C.push(now);
  }
  long long ans = -1e17;
  for (int i = 0; i <= k; i++) {
    ans = max(ans, r[i] + c[k - i] - p * i * (k - i));
  }
  cout << ans << endl;
}
