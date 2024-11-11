#include <bits/stdc++.h>
using namespace std;
int a[100007];
bool vt[1 << 20];
int main() {
  int i, j, k;
  int n;
  while (~scanf("%d", &n)) {
    memset((vt), (false), sizeof(vt));
    int res = 0;
    for (i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      if (!vt[a[i]]) {
        vt[a[i]] = true;
        res++;
      }
      for (j = 0; j <= 20; ++j) {
        if (a[i] & (1 << j)) {
          int st = a[i];
          for (k = i - 1; k >= 0 && !(a[k] & (1 << j)); --k) {
            st |= a[k];
            if (!vt[st]) {
              vt[st] = true;
              res++;
            }
          }
        }
      }
      vt[a[i]] = true;
    }
    cout << res << endl;
  }
  return 0;
}
