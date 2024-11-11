#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using mii = map<INT, INT>;
INT n, k;
mii mp, cnt;
mii ::iterator it;
inline void get(INT n) {
  mp.clear();
  cnt.clear();
  mp[n] = 1;
  while (!mp.empty()) {
    INT now = mp.rbegin()->first, c = mp.rbegin()->second;
    mp.erase(--mp.end());
    INT l = now - 1 >> 1, r = now - l - 1;
    cnt[l] += c;
    if (l) mp[l] += c;
    if (r) mp[r] += c;
  }
}
INT calc(INT st, INT ed, INT len) {
  INT mid = st + ed >> 1;
  if (k == 1 and mid - st == len) return mid;
  if (st < mid)
    get(mid - st);
  else
    cnt[len] = mid - st == len;
  if (k <= cnt[len]) return calc(st, mid - 1, len);
  k -= cnt[len];
  return calc(mid + 1, ed, len);
}
INT solve() {
  if (k == 1) return 1;
  if (k == 2) return n;
  k -= 2;
  get(n - 2);
  INT len;
  for (it = cnt.end();;) {
    it--;
    if (k > it->second)
      k -= it->second;
    else {
      len = it->first;
      break;
    }
  }
  return calc(2, n - 1, len);
}
int main() {
  cin >> n >> k;
  cout << solve() << endl;
}
