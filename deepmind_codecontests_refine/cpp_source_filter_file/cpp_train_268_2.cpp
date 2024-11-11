#include <bits/stdc++.h>
using namespace std;
long long n, k, m;
long long t[50];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m;
  for (long long i = 0; i < k; i++) cin >> t[i];
  long long total = 0;
  for (long long i = 0; i < k; i++) total += t[i];
  sort(t, t + k);
  long long best = 0;
  for (long long i = 0; i <= n; i++) {
    long long left = m - i * total;
    if (left < 0) break;
    long long cur = i * (k + 1);
    long long cur_sub = 0;
    while (left > 0 && cur_sub < k) {
      for (long long j = 0; j < n; j++) {
        left -= t[cur_sub];
        if (left >= 0) cur++;
        if (cur_sub == k - 1 && left >= 0) cur++;
        if (left <= 0) break;
      }
      cur_sub++;
    }
    if (cur > best) {
      best = cur;
    }
  }
  cout << best << '\n';
}
