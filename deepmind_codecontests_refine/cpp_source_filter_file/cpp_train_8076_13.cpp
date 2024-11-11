#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long k;
  cin >> k;
  long long ans = 0;
  for (long long level = -k; level <= k; level++) {
    long long left, right;
    if (level % 2 == 0) {
      if (3 * level * level + 4 * 1 * 1 > 4 * k * k) continue;
      if (3 * 4 * (level + 1) * (level + 1) + 4 * 1 * 1 > 4 * 4 * k * k) {
        continue;
      }
      if (3 * 4 * (level - 1) * (level - 1) + 4 * 1 * 1 > 4 * 4 * k * k) {
        continue;
      }
      long long l = 0, r = 1e6;
      while (l < r - 1) {
        long long mid = (l + r) / 2;
        long long x = 3 * mid + 1;
        long long xu = 6 * mid + 1;
        if (4 * x * x + 3 * level * level <= 4 * k * k &&
            4 * xu * xu + 3 * 4 * (level + 1) * (level + 1) <= 4 * 4 * k * k &&
            4 * xu * xu + 3 * 4 * (level - 1) * (level - 1) <= 4 * 4 * k * k)
          l = mid;
        else
          r = mid;
      }
      right = l;
      l = -1e6, r = 0;
      while (l < r - 1) {
        long long mid = (l + r) / 2;
        long long x = 3 * mid - 1;
        long long xu = 6 * mid - 1;
        if (4 * x * x + 3 * level * level <= 4 * k * k &&
            4 * xu * xu + 3 * 4 * (level + 1) * (level + 1) <= 4 * 4 * k * k &&
            4 * xu * xu + 3 * 4 * (level - 1) * (level - 1) <= 4 * 4 * k * k)
          r = mid;
        else
          l = mid;
      }
      left = r;
    } else {
      if (3 * 4 * level * level + 4 * 5 * 5 > 4 * 4 * k * k) continue;
      if (3 * (level + 1) * (level + 1) + 4 * 2 * 2 > 4 * k * k) continue;
      if (3 * (level - 1) * (level - 1) + 4 * 2 * 2 > 4 * k * k) continue;
      long long l = 0, r = 1e6;
      while (l < r - 1) {
        long long mid = (l + r) / 2;
        long long x = 6 * mid + 5;
        long long xu = 3 * mid + 2;
        if (4 * x * x + 3 * 4 * level * level <= 4 * 4 * k * k &&
            4 * xu * xu + 3 * (level + 1) * (level + 1) <= 4 * k * k &&
            4 * xu * xu + 3 * (level - 1) * (level - 1) <= 4 * k * k)
          l = mid;
        else
          r = mid;
      }
      right = l;
      l = -1e6, r = -1;
      while (l < r - 1) {
        long long mid = (l + r) / 2;
        long long x = 6 * mid + 1;
        long long xu = 3 * mid + 1;
        if (4 * x * x + 3 * 4 * level * level <= 4 * 4 * k * k &&
            4 * xu * xu + 3 * (level + 1) * (level + 1) <= 4 * k * k &&
            4 * xu * xu + 3 * (level - 1) * (level - 1) <= 4 * k * k)
          r = mid;
        else
          l = mid;
      }
      left = r;
    }
    ans += right - left + 1;
  }
  cout << ans << endl;
  return 0;
}
