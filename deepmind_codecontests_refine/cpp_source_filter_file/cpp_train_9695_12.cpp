#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int a[110], t[110];
bool ext[110];
int main() {
  int n, ans = 0, lost = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  std::sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i + 1]) ext[i] = ext[i + 1] = true, lost += 2;
  }
  for (int i = 1, j = 1; i <= n - lost && j <= n; ++i, ++j) {
    if (!ext[j])
      t[i] = a[j];
    else
      --i;
  }
  for (int i = n - lost; i >= 1; i -= 2) {
    ans = ans + t[i] - t[i - 1];
  }
  cout << ans;
  return 0;
}
