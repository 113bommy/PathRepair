#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MXN = 1e5 + 1;
int n;
int a[MXN], b[MXN], id[MXN], id1[MXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    id[b[i]] = i;
  }
  vector<pair<int, int> > res;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] == a[i]) continue;
    int pos = 0, last;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] == b[i]) {
        pos = j;
        break;
      }
    }
    last = pos;
    for (pos--; pos >= i; pos--) {
      if (id[a[pos]] > pos) {
        swap(a[pos], a[last]);
        res.push_back({pos, last});
        sum += last - pos;
        last = pos;
      }
    }
  }
  printf("%d\n%d\n", sum, (int)res.size());
  for (int i = 0; i < res.size(); i++) {
    printf("%d %d\n", res[i].first, res[i].second);
  }
  return 0;
}
