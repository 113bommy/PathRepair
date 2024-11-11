#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  n++;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<long long> was = v;
  int pos = -1;
  for (int i = 0; i < n - 1; ++i) {
    long long cnt = v[i] / 2;
    v[i] -= cnt * 2;
    v[i + 1] += cnt;
    if (pos == -1 && v[i] != 0) {
      pos = i;
    }
  }
  if (pos == -1) {
    pos = n - 1;
  }
  long long cnt = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (i > pos) {
      cnt *= 2;
      cnt -= v[i];
      if (abs(cnt) > 5 * k) {
        cout << 0;
        return 0;
      }
      continue;
    }
    if (i <= pos) {
      cnt *= 2;
      cnt -= v[i];
      long long tmp = cnt + was[i];
      if (abs(tmp) <= k) {
        if (i == n - 1 && tmp == 0) ans--;
        ans++;
      }
      if (abs(cnt) > 5 * k) {
        cout << ans;
        return 0;
      }
    }
  }
  cout << ans;
  return 0;
}
