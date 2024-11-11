#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, *pn, mx = 0;
  cin >> n;
  pn = (int*)malloc(sizeof(int) * n);
  memset(pn, 0, sizeof(int) * n);
  for (int i = 0; i < n; i++) cin >> pn[i];
  for (int i = 0; i <= n - 1; i++)
    for (int j = 0; j < n; j++) {
      int tmp = 0, *tp;
      tp = (int*)malloc(sizeof(int) * n);
      memcpy(tp, pn, sizeof(int) * n);
      for (int k = i; k <= j; k++) tp[k] ^= 1;
      for (int x = 0; x < n; x++) tmp += tp[x];
      if (tmp > mx) mx = tmp;
    }
  cout << mx;
  return 0;
}
