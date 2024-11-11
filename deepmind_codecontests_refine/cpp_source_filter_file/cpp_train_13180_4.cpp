#include <bits/stdc++.h>
using namespace std;
int l[101], r[101];
int n;
bool check() {
  int tou = 0;
  for (int i = 1; i <= n; i++)
    if (l[i] == 0) tou++;
  int wei = 0;
  for (int i = 1; i <= n; i++)
    if (r[i] == 0) wei++;
  if (tou == 1 && wei == 1) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n) {
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    while (!check()) {
      int wei;
      for (int i = 1; i <= n; i++)
        if (r[i] == 0) {
          wei = i;
          break;
        }
      int tou;
      for (int i = 1; i <= n; i++)
        if (l[i] == 0) {
          int j = i;
          while (r[j] != 0) j = r[j];
          if (i != j) {
            tou = i;
            break;
          }
        }
      r[wei] = tou;
      l[tou] = wei;
    }
    for (int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << '\n';
  }
  return 0;
}
