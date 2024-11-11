#include <bits/stdc++.h>
using namespace std;
using num = int64_t;
num get_k(num h, const num a, const num b) {
  if (h <= a) return 0;
  bool subtracted = false;
  if (h % (a + b) == 0) {
    --h;
    subtracted = true;
  }
  h %= (a + b);
  if (subtracted) {
    ++h;
  }
  assert(h <= (a + b));
  if (h <= a) return 0;
  num res = h / a;
  h %= a;
  if (h > 0) ++res;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  num n, a, b, k;
  cin >> n >> a >> b >> k;
  map<num, num> count;
  for (int i = 0; i < n; ++i) {
    num h;
    cin >> h;
    num req = get_k(h, a, b);
    count[req] += 1;
  }
  int res = 0;
  for (auto it : count) {
    if (it.first > k) {
      break;
    }
    if (it.first == 0) {
      res += it.second;
      continue;
    }
    num to_add = max(it.second, k / it.first);
    assert(to_add >= 0);
    k -= to_add * it.first;
    assert(k >= 0);
    res += to_add;
  }
  cout << res << endl;
  return 0;
}
