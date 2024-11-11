#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
int a[N];
long long cont[22][2];
void merge_sort(int l, int r, int dep) {
  if (l >= r) return;
  int m = (l + r) >> 1;
  merge_sort(l, m, dep - 1);
  merge_sort(m + 1, r, dep - 1);
  for (int i = l; i <= m; i++) {
    cont[dep][0] += (lower_bound(a + m + 1, a + r + 1, a[i]) - (a + m + 1));
    cont[dep][1] +=
        r - m - (upper_bound(a + m + 1, a + r + 1, a[i]) - (a + m + 1));
  }
  sort(a + l, a + r + 1);
}
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= (1 << n); i++) cin >> a[i];
    memset(cont, 0, sizeof(cont));
    merge_sort(1, (1 << n), n);
    int m;
    cin >> m;
    while (m--) {
      int q;
      cin >> q;
      for (int i = 1; i <= q; i++) swap(cont[i][0], cont[i][1]);
      long long res = 0;
      for (int i = 1; i <= q; i++) res += cont[i][0];
      cout << res << endl;
    }
  }
  return 0;
}
