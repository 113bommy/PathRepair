#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int Q;
  cin >> Q;
  for (int z = 0; z < Q; z++) {
    int n;
    cin >> n;
    int left = -100000, right = 100000, top = 100000, bot = -100000;
    for (int i = 0; i < n; i++) {
      int x, y, f1, f2, f3, f4;
      cin >> x >> y >> f1 >> f2 >> f3 >> f4;
      if (f1 == 0) {
        left = max(x, left);
      }
      if (f2 == 0) {
        top = min(top, y);
      }
      if (f3 == 0) {
        right = min(right, x);
      }
      if (f4 == 0) {
        bot = max(bot, y);
      }
    }
    if (left <= right && bot <= top) {
      cout << 1 << ' ' << left << ' ' << top << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}
