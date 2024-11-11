#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 2;
int n, ar[MAX], ans = 1e9, aa, dd;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  for (int i = 0; i < MAX * 2; i++) {
    int res, p1 = -1e9, p2 = -1e9;
    for (int j = 0; j < n; j++) p1 = max(p1, ar[j] - j * i);
    for (int j = 0; j < n; j++) p2 = max(p2, j * i - ar[j]);
    res = (p1 + p2 + 1) / 2;
    if (res < ans) ans = res, dd = i, aa = p1 - res;
  }
  cout << ans << '\n' << aa << " " << dd;
}
