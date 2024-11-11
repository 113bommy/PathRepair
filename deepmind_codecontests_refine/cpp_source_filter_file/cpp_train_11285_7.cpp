#include <bits/stdc++.h>
using namespace std;
int a[100005];
int visit[100005];
bool cmp(int x, int y) { return x > y; }
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 29; i > 0; i--) {
      int v = 1 << i;
      memset(visit, 0, sizeof(int) * (n + 2));
      int temp = -1;
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] & v) {
          if (temp == -1)
            temp = a[j];
          else
            temp &= a[j];
          visit[j] = 1;
          sum++;
        }
      }
      if (temp % v == 0) {
        cout << sum << endl;
        for (int i = n - 1; i >= 0; i--) {
          if (visit[i]) cout << a[i] << ' ';
        }
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
