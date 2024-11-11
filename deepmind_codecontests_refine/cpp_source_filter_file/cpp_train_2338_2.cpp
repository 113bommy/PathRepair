#include <bits/stdc++.h>
using namespace std;
const int size = 500005;
long long presum[size], x;
int cnt[size];
int main() {
  int n;
  long long y = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    y += x;
    presum[i] = x;
  }
  long long ss = 0;
  for (int i = n - 1; i >= 0; i--) {
    ss += presum[i];
    if (ss == y / 3) cnt[i] = 1;
  }
  cnt[n] = 0;
  for (int i = n - 1; i >= 0; i--) cnt[i] += cnt[i + 1];
  if (y % 3 != 0)
    cout << "0\n";
  else {
    int ans = 0;
    long long ss = 0;
    for (int i = 0; i + 2 < n; i++) {
      ss += presum[i];
      if (ss == y / 3) ans += cnt[i + 2];
    }
    cout << ans << "\n";
  }
  return 0;
}
