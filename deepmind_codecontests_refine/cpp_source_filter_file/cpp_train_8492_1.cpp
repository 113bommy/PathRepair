#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 9;
int n, sq, a[MAX], group[MAX];
struct Bucket {
  Bucket() : l(1), r(0) {}
  int l, r, freq[MAX], cnt;
} buckets[320];
void add(int idx, int k) {
  for (int i = buckets[idx].r + 1; i <= n; ++i) {
    if (!buckets[idx].freq[a[i]]) {
      if (buckets[idx].cnt == k) {
        return;
      } else {
        ++buckets[idx].cnt;
      }
    }
    ++buckets[idx].freq[a[i]];
    buckets[idx].r = i;
  }
}
void del(int idx, int lst) {
  for (int i = buckets[idx].l; i <= min(buckets[idx].r, lst); ++i) {
    --buckets[idx].freq[a[i]];
    if (!buckets[idx].freq[a[i]]) {
      --buckets[idx].cnt;
    }
  }
  buckets[idx].l = lst + 1;
  buckets[idx].r = max(buckets[idx].r, lst);
}
int naive(int k) {
  for (int i = 1; i <= n; ++i) {
    group[i] = 0;
  }
  int cnt = 0, curGroup = 1;
  for (int i = 1; i <= n; ++i) {
    if (group[a[i]] != curGroup && cnt == k) {
      ++curGroup;
      cnt = 0;
    }
    if (group[a[i]] != curGroup) {
      ++cnt;
      group[a[i]] = curGroup;
    }
  }
  return curGroup;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  sq = (int)sqrt(n + .0) + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int k = 1; k <= sq; ++k) {
    cout << naive(k) << " ";
  }
  for (int k = sq + 1; k <= n; ++k) {
    add(1, k);
    int lst = buckets[1].r, curBucket = 1;
    while (lst < n) {
      ++curBucket;
      del(curBucket, lst);
      add(curBucket, k);
      lst = buckets[curBucket].r;
    }
    cout << curBucket << " ";
  }
  return 0;
}
