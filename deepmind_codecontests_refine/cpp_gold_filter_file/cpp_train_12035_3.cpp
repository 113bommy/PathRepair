#include <bits/stdc++.h>
using namespace std;
class fastio {
 public:
  fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} __fastio;
map<long long, long long> go(long long n) {
  map<long long, long long> m[100];
  m[0][-n] = 1;
  long long cc = 0;
  map<long long, long long> ans;
  ans[-(n - 1) / 2]++;
  int ok = 1;
  while (ok) {
    ok = 0;
    for (auto it : m[cc]) {
      long long w = -it.first;
      if ((w - 1) / 2 > 0) {
        ok = 1;
        m[cc + 1][-(w - 1) / 2] += it.second;
        ans[-((w - 1) / 2 - 1) / 2] += it.second;
      }
      if (w / 2 > 0) {
        m[cc + 1][-w / 2] += it.second;
        ans[-(w / 2 - 1) / 2] += it.second;
        ok = 1;
      }
    }
    cc++;
  }
  return ans;
}
long long n, k;
long long solve() {
  long long pos = 1, sz = 0;
  auto aa = go(n);
  for (auto it : aa) {
    if (it.second >= k) {
      sz = -it.first;
      break;
    }
    k -= it.second;
  }
  long long cursz = (n - 1) / 2;
  long long size = n;
  while (true) {
    if (cursz == sz) {
      return pos + sz + k;
    }
    auto a1 = go((size - 1) / 2);
    auto a2 = go(size / 2);
    if (a1[-sz] >= k) {
      if (size == 2) pos++;
      size = cursz;
      cursz = (cursz - 1) / 2;
    } else {
      pos += cursz + 1;
      k -= a1[-sz];
      cursz = (size / 2 - 1) / 2;
      size = size / 2;
    }
  }
  return -1;
}
int main() {
  cin >> n >> k;
  if (k == 1) {
    cout << 1;
    return 0;
  }
  if (k == 2) {
    cout << n;
    return 0;
  }
  k -= 2;
  n -= 2;
  cout << solve();
}
