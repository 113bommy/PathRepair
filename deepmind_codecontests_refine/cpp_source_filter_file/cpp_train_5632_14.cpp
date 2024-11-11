#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[207], ma[207];
bool cmp(int x, int y) { return x > y; }
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ma[a[i]]++;
  }
  int sum = 0;
  sort(ma, ma + 107, cmp);
  int ans = 0;
  for (int j = 1; j <= 100; j++) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      if (ma[i] < j) {
        cnt++;
      }
      if (ma[i] >= j) {
        cnt = cnt - ma[i] / j + 1;
      }
    }
    if (cnt > 0) {
      ans = j - 1;
      break;
    }
  }
  cout << ans << endl;
}
