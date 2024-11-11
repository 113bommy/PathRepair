#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n, m, w, memory[100005], b[100005];
  while (cin >> n >> m >> w) {
    int l = 0x7FFFFFFF, r = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] < l) l = a[i];
      if (a[i] > r) r = a[i];
    }
    r += m;
    while (l <= r) {
      int tempm = m;
      int mid = (l + r) >> 1;
      for (int i = 0; i < n; i++) {
        b[i] = mid - a[i];
        if (b[i] <= 0) b[i] = 0;
      }
      memset(memory, 0, sizeof(memory));
      int index = 0, flag = 0, x = 0;
      for (int i = 0; i < n; i++) {
        x += memory[i];
        if ((b[i] - x) > 0) {
          b[i] -= x;
          tempm -= b[i];
          if (tempm < 0) {
            flag = 1;
            break;
          }
          x += b[i];
          memory[i + w] -= b[i];
        }
      }
      if (tempm >= 0)
        l = mid + 1;
      else
        r = mid - 1;
    }
    printf("%d\n", l - 1);
  }
}
