#include <bits/stdc++.h>
int n, k;
std::vector<int> minv(std::vector<int> &a, std::vector<int> &b) {
  if (a.size() < b.size()) return a;
  if (b.size() < a.size()) return b;
  for (int i = a.size() - 1; i >= 0; i--) {
    if (a[i] < b[i]) return a;
    if (b[i] < a[i]) return b;
  }
  return a;
}
bool attempt(int tot, int overflows, std::vector<int> &res) {
  if (tot < 0) return false;
  if (tot == 0 && overflows == 0) return true;
  if (overflows > 0) {
    for (int i = 8; i >= 0; i--) {
      int next = i * k + overflows;
      if (tot - next < 0) continue;
      if ((tot - next) % (k + 1) != 0) break;
      res.push_back(i);
      return attempt(tot - next, 0, res);
    }
    res.push_back(9);
    if (attempt(tot - (k + 1 - overflows) * 9, overflows, res)) return true;
    res.pop_back();
    return false;
  }
  if (tot % (k + 1) != 0) return false;
  for (int i = 9; i >= 1; i--) {
    int next = i * (k + 1);
    if (tot - next < 0) continue;
    res.push_back(i);
    return attempt(tot - next, overflows, res);
  }
  assert(false);
}
void solve() {
  scanf("%d %d", &n, &k);
  std::vector<int> best;
  for (int start = 0; start < 10; start++) {
    std::vector<int> curr;
    curr.push_back(start);
    int overflows = std::max(0, start + k - 10 + 1);
    int tot = (start + (start + k)) * (k + 1) / 2 - overflows * 10;
    if (attempt(n - tot, overflows, curr)) {
      while (curr.size() > 1 && curr.back() == 0) curr.pop_back();
      if (best.empty())
        best = curr;
      else
        best = minv(best, curr);
    }
  }
  if (best.empty()) {
    printf("-1\n");
  } else {
    for (int i = best.size() - 1; i >= 0; i--) {
      printf("%d", best[i]);
    }
    printf("\n");
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
