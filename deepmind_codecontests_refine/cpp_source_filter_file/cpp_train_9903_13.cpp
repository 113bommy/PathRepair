#include <bits/stdc++.h>
using namespace std;
class idler {
 public:
  int a, b;
};
void qsort(vector<idler>& c, int l, int r) {
  int x = c[(l + r) / 2].b;
  int i = l, j = r;
  do {
    while (c[i].b < x) ++i;
    while (c[j].b > x) --j;
    if (i <= j) {
      swap(c[i], c[j]);
      ++i;
      --j;
    }
  } while (i < j);
  if (l < j) qsort(c, l, j);
  if (i < r) qsort(c, i, r);
}
int main() {
  int n, k, i, dem = 0;
  cin >> n >> k;
  vector<idler> c(n);
  vector<int> cnt(k + 1);
  for (i = 0; i < n; ++i) {
    cin >> c[i].a;
    ++cnt[c[i].a];
  }
  for (i = 0; i < n; ++i) {
    cin >> c[i].b;
  }
  for (i = 1; i <= k; ++i) {
    if (cnt[i] == 0) {
      ++dem;
    }
  }
  qsort(c, 0, n - 1);
  long sum = 0;
  i = 0;
  while (dem > 0) {
    if (--cnt[c[i].a]) {
      sum += c[i].b;
      --dem;
    }
    ++i;
  }
  cout << sum;
}
