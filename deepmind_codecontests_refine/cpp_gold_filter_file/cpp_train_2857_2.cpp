#include <bits/stdc++.h>
using namespace std;
const int MaxVal = 1e9, Nmax = 3e5 + 5;
long long sum = 0, ans, nr;
int n, i, w, poz, ord[Nmax], c[Nmax];
pair<int, int> b[Nmax];
pair<pair<int, int>, int> a[Nmax];
bool used[Nmax];
class SegmentTree {
  int cnt;
  long long sum;
  SegmentTree *left, *right;

 public:
  SegmentTree() {
    cnt = sum = 0;
    left = right = NULL;
  }
  void update(int st, int dr, int poz, int add) {
    cnt += add;
    sum += add * poz;
    if (st == dr) return;
    if (poz <= ((st + dr) / 2)) {
      if (!left) left = new SegmentTree;
      left->update(st, ((st + dr) / 2), poz, add);
    } else {
      if (!right) right = new SegmentTree;
      right->update(((st + dr) / 2) + 1, dr, poz, add);
    }
  }
  long long get_ans(int st, int dr, int k) {
    if (st == dr) {
      if (k <= cnt)
        return 1LL * k * st;
      else
        return 1LL * MaxVal * Nmax;
    }
    if (!left) left = new SegmentTree;
    int nr = left->cnt;
    if (k <= nr)
      return left->get_ans(st, ((st + dr) / 2), k);
    else {
      if (!right) right = new SegmentTree;
      return left->sum + right->get_ans(((st + dr) / 2) + 1, dr, k - nr);
    }
  }
} aint;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.second == b.first.second) return a.first.first < b.first.first;
  return a.first.second < b.first.second;
}
int main() {
  scanf("%d%d", &n, &w);
  for (i = 1; i <= n; ++i)
    scanf("%d%d", &a[i].first.first, &a[i].first.second), a[i].second = i;
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= n; ++i) ord[a[i].second] = i;
  for (i = 1; i <= n; ++i) aint.update(1, MaxVal, a[i].first.first, 1);
  ans = aint.get_ans(1, MaxVal, w);
  poz = 0;
  for (i = 1; i <= n && i <= w; ++i) {
    aint.update(1, MaxVal, a[i].first.first, -1);
    aint.update(1, MaxVal, a[i].first.second - a[i].first.first, 1);
    sum += a[i].first.first;
    nr = sum + aint.get_ans(1, MaxVal, w - i);
    if (nr < ans) ans = nr, poz = i;
  }
  printf("%lld\n", ans);
  for (i = 1; i <= poz; ++i) b[i] = {a[i].first.second - a[i].first.first, i};
  for (; i <= n; ++i) b[i] = {a[i].first.first, i};
  sort(b + 1, b + n + 1);
  for (i = 1; i <= w - poz; ++i) c[b[i].second] = 1;
  for (i = 1; i <= poz; ++i) ++c[i];
  for (i = 1; i <= n; ++i) printf("%d", c[ord[i]]);
  printf("\n");
  return 0;
}
