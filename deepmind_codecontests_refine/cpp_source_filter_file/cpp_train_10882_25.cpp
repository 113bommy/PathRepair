#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 1000000005;
int x[MAX_N];
struct name {
  int left, right;
};
name key[MAX_N];
long long bin(long long m, long long l, long long r) {
  int left = l, right = r, mid;
  long long a, b;
  while (left <= right) {
    mid = left + (right - left) / 2;
    a = (mid + l) * (mid - l + 1) / 2;
    if (m - a >= 0 && m - a < mid + 1) return mid;
    if (a < m) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
}
int main() {
  long long n, m, left = 1, ans = 0, h = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (left == x[i]) left++;
  }
  x[n] = MAX_M;
  n++;
  sort(x, x + n);
  for (int i = 0; i < n; i++) {
    if (left < x[i]) {
      long long a;
      a = (x[i] - 1 + left) * (x[i] - left) / 2;
      if (a <= m) {
        key[h].left = left;
        key[h].right = x[i] - 1;
        m -= a;
        ans += x[i] - left;
        left = x[i] + 1;
        h++;
      } else {
        a = bin(m, left, x[i] - 1);
        if (a < m) {
          key[h].left = left;
          key[h].right = a;
          h++;
          ans += a - left + 1;
        }
        break;
      }
      if (m == 0) break;
    } else
      left = x[i] + 1;
  }
  cout << ans << endl;
  for (int i = 0; i < h; i++) {
    for (int j = key[i].left; j <= key[i].right; j++) {
      cout << j << " ";
    }
  }
  return 0;
}
