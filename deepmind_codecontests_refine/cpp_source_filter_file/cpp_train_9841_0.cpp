#include <bits/stdc++.h>
using namespace std;
long long n, k, b, c;
long long t[200005];
long long val = (1ll << 60);
priority_queue<long long> q;
long long f_abs(long long x) { return x < 0 ? -x : x; }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> b >> c;
  b = min(b, 5 * c);
  for (int i = 1; i <= n; i++) cin >> t[i];
  sort(t + 1, t + n + 1);
  for (int i = -1000000000; i <= -1000000000 + 4; i++) {
    while (!q.empty()) q.pop();
    long long ans = i, cnt = 0;
    for (int j = 1; j <= n; j++) {
      long long w = 0;
      if (ans < t[j]) {
        ans = t[j];
        while (f_abs(ans % 5) != f_abs(i % 5)) {
          ans++;
          w += c;
        }
      } else {
        long long temp = t[j];
        while (f_abs(ans % 5) != f_abs(temp % 5)) {
          temp++;
          w += c;
        }
      }
      cnt = cnt + w - b * ((ans - i) / 5 - 1);
      q.push(w - b * ((ans - i) / 5 - 1));
      if (q.size() > k) {
        cnt -= q.top();
        q.pop();
      }
      if (q.size() == k) val = min(val, cnt + k * b * ((ans - i) / 5 - 1));
    }
  }
  cout << val;
  return 0;
}
