#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int ans[MAXN], BIT[MAXN];
int que(int pos) {
  int ret = 0;
  while (pos > 0) {
    ret += BIT[pos];
    pos -= (pos & (-pos));
  }
  return ret;
}
void upd(int pos, int val) {
  while (pos < MAXN) {
    BIT[pos] += val;
    pos += (pos & (-pos));
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > A(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i].first);
    A[i].second = i + 1;
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < n; ++i) {
    int cpos = A[i].second;
    for (int k = 1; k * (cpos - 1) + 2 <= n && k < n; ++k)
      ans[k] += que(min(n, k * cpos + 1)) - que(k * (cpos - 1) + 1);
    upd(cpos, 1);
  }
  for (int i = 1; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
