#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005], Left[500005], Right[500005];
int n, m, tot;
void Solve() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  Left[n + 1] = Right[0] = 0;
  for (i = 1; i <= n; ++i) {
    Right[i] = Right[i - 1];
    if (a[i]) ++Right[i];
  }
  for (i = n; i >= 1; --i) {
    Left[i] = Left[i + 1];
    if (!a[i]) ++Left[i];
  }
  int l = 1, r = n;
  long long ans = 0;
  while (l <= r) {
    if (a[l] == 0)
      ++l;
    else if (a[r] == 1)
      --r;
    else {
      if (Left[l] - Left[r + 1] < Right[r] - Right[l - 1]) {
        ans += Left[l] - Left[r + 1];
        ++l;
      } else
        ans += Right[r] - Right[l - 1], --r;
    }
  }
  cout << ans << endl;
}
int main() {
  Solve();
  cin >> n;
  return 0;
}
