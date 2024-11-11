#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int b[500000 + 1], a[500000 + 1], cnt[500000 + 1], need[500000 + 1];
int kind = 0;
int m, k, n, s;
bool check(int l, int r) {
  vector<int> v;
  int need_ = max(0, (r - l + 1) - k);
  int len = min(r - l + 1, k);
  int z = (l - 1) / k;
  int st = 1 + z * k;
  int add = st + k - 1;
  add = min(add, n * k);
  int ar = r;
  r = min(r, l + len - 1);
  need_ += max(0, r - add);
  if (need_ > m - (k * n)) return 0;
  for (int i = 1; i <= r - add; ++i) {
    v.push_back(i);
  }
  need_ -= max(0, r - add);
  r = ar;
  memset(cnt, 0, sizeof(cnt));
  if (need_)
    for (int i = l; i <= r; ++i) {
      cnt[a[i]]++;
      if (cnt[a[i]] - 1 >= need[a[i]]) {
        cnt[a[i]]--;
        v.push_back(i);
        need_--;
        if (need_ == 0) {
          break;
        }
      }
    }
  cout << v.size() << endl;
  for (auto it : v) {
    cout << it << " ";
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> m >> k >> n >> s;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 1; i <= s; ++i) {
    cin >> b[i];
    need[b[i]]++;
    if (need[b[i]] == 1) {
      kind++;
    }
  }
  int r = -1;
  int ok = 0;
  vector<pair<int, int> > seg;
  for (int i = 1; i <= m; ++i) {
    cnt[a[i]]++;
    if (cnt[a[i]] == need[a[i]]) {
      ok++;
    }
    if (ok == kind) {
      r = i;
      break;
    }
  }
  if (r == -1) {
    cout << -1 << endl;
    exit(0);
  }
  seg.push_back(make_pair(1, r));
  for (int i = 2; i <= m; ++i) {
    cnt[a[i - 1]]--;
    if (cnt[a[i - 1]] + 1 == need[a[i - 1]]) {
      ok--;
      for (int j = r + 1; j <= m; ++j) {
        cnt[a[j]]++;
        if (cnt[a[j]] == need[a[j]]) {
          r = j;
          ok++;
          break;
        }
      }
      if (ok != kind) {
        r = -1;
      }
    }
    if (r == -1) break;
    seg.push_back(make_pair(i, r));
  }
  for (auto it : seg) {
    if (check(it.first, it.second)) {
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
