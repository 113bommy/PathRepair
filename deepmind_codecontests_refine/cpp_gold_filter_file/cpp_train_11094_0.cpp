#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m;
long long A[N], D[N];
set<int> pts;
unordered_set<int> nonzero;
map<int, int> cnt;
bool isExtr(int k) {
  if (k == 0 || k == n - 1) return true;
  if (D[k] == 0 || D[k + 1] == 0) return true;
  if (D[k] < 0 && D[k + 1] > 0) return true;
  return false;
}
void init() {
  int cur = 0;
  for (auto it = ++pts.begin(); it != pts.end(); ++it) {
    int x = *it;
    cnt[x - cur]++;
    cur = x;
  }
  return;
}
void updateCnt(int k, bool ok1, bool ok2) {
  if (ok1 && ok2) return;
  if (!ok1 && !ok2) return;
  if (ok1 && !ok2) {
    pts.erase(k);
    auto it1 = pts.upper_bound(k), it2 = --pts.upper_bound(k);
    int j = *it2, l = *it1;
    cnt[l - k]--;
    if (cnt[l - k] == 0) cnt.erase(l - k);
    cnt[k - j]--;
    if (cnt[k - j] == 0) cnt.erase(k - j);
    cnt[l - j]++;
    return;
  } else {
    auto it1 = pts.upper_bound(k), it2 = --pts.upper_bound(k);
    int j = *it2, l = *it1;
    cnt[l - k]++;
    cnt[k - j]++;
    cnt[l - j]--;
    if (cnt[l - j] == 0) cnt.erase(l - j);
    pts.insert(k);
    return;
  }
}
void update(int k, long long x) {
  bool ok1 = isExtr(k), ok2 = isExtr(k - 1);
  D[k] += x;
  if (D[k] != 0)
    nonzero.insert(k);
  else
    nonzero.erase(k);
  bool ok3 = isExtr(k), ok4 = isExtr(k - 1);
  updateCnt(k, ok1, ok3);
  updateCnt(k - 1, ok2, ok4);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n;
  D[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (i) {
      D[i] = A[i] - A[i - 1];
      if (D[i] != 0) nonzero.insert(i);
    }
  }
  for (int i = 0; i < n; i++)
    if (isExtr(i)) pts.insert(i);
  init();
  cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    long long x;
    cin >> l >> r >> x;
    if (l != 1) update(l - 1, x);
    if (r < n) update(r, -x);
    if (nonzero.empty())
      cout << 1 << endl;
    else
      cout << (--cnt.end())->first + 1 << endl;
  }
  return 0;
}
