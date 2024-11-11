#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int maxm = 40 + 5;
int a[maxm], id[maxm], ans[maxn], n, m;
bool cmp(const int &x, const int &y) { return a[x] > a[y]; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < m; ++i) id[i] = i;
  sort(id, id + m, cmp);
  vector<int> bak;
  for (int lo = 0, hi = m - 1; lo <= hi; lo++, hi--) {
    bak.push_back(id[lo]);
    if (lo < hi) {
      bak.push_back(id[hi]);
    }
  }
  for (int i = 0; i < m; ++i) id[i] = bak[i];
  int pos = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; a[id[i]] && j < n; ++j) {
      if (ans[(pos + j) % n] >= 0) continue;
      if (ans[(pos + j + 1) % n] == id[i]) {
        pos = (pos + j) % n;
        break;
      }
      ans[(pos + j) % n] = id[i];
      j++;
      a[id[i]]--;
      if (a[id[i]] == 0) {
        pos = (pos + j + 1) % n;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1) {
      puts("-1");
      return 0;
    }
  }
  printf("%d", ans[0] + 1);
  for (int i = 1; i < n; ++i) {
    printf(" %d", ans[i] + 1);
  }
  puts("");
  return 0;
}
