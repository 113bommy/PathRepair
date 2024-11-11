#include <bits/stdc++.h>
using namespace std;
int xsolve(int h, int n) {
  ++h;
  vector<char> used(1 << h);
  int offset = 1 << (h - 1);
  int target = offset + (n - 1);
  int v = 1;
  used[v] = 1;
  int ans = 1;
  int dir = 0;
  int skip = 0;
  for (;; dir = 1 - dir) {
    int to = 2 * v + dir;
    if (used[to]) {
      ++skip;
      if (skip >= 2) {
        v /= 2;
        skip = 0;
      }
      continue;
    } else {
      if (to == target) break;
      skip = 0;
      v = to;
      used[v] = 1;
      ++ans;
      if (v >= offset) {
        v /= 2;
      }
    }
  }
  return ans;
}
long long fsolve(long long h, long long n) {
  long long target = (1LL << h) + (n - 1);
  vector<int> b;
  for (long long m = target; m > 1; m >>= 1) b.push_back(m & 1);
  reverse(b.begin(), b.end());
  long long H = h;
  long long ans = 1;
  int dir = 0;
  for (int i = 0; i < b.size(); ++i) {
    if (b[i] != dir) {
      ans += (1LL << H) - 1LL;
      dir = 1 - dir;
    }
    ++ans;
    --H;
    dir = 1 - dir;
  }
  return ans - 1;
}
int main() {
  long long h, n;
  cin >> h >> n;
  cout << fsolve(h, n);
  return 0;
}
