#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
int ara[20];
int main() {
  int n, a = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ara[i];
    int b = ara[i];
    ara[i] = ara[i] - a;
    a = b;
  }
  if (n == 1) return cout << 1 << endl, 0;
  int j = 1;
  int ans = 1;
  for (int i = 1; i <= n; i += 2) {
    if (ara[i] >= 0 && ara[i + 1] >= 0)
      ara[j++] = 1, ans = 2;
    else
      ara[j++] = 0;
  }
  if (n / 2 == 1) return cout << ans << endl, 0;
  j = 1;
  for (int i = 1; i <= n / 2; i += 2) {
    if (ara[i] > 0 && ara[i + 1] > 0)
      ara[j++] = 1, ans = 4;
    else
      ara[j++] = 0;
  }
  j = 1;
  if (n / 4 == 1) return cout << ans << endl, 0;
  for (int i = 1; i <= n / 4; i += 2) {
    if (ara[i] > 0 && ara[i + 1] > 0)
      ara[j++] = 1, ans = 8;
    else
      ara[j++] = 0;
  }
  j = 1;
  if (n / 8 == 1) return cout << ans << endl, 0;
  for (int i = 1; i <= n / 8; i += 2) {
    if (ara[i] > 0 && ara[i + 1] > 0)
      ara[j++] = 1, ans = 16;
    else
      ara[j++] = 0;
  }
  cout << ans << endl;
}
