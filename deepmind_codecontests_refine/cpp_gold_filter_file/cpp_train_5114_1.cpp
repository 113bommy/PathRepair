#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, ans = 0;
  cin >> n;
  vector<int> a(n), b(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n - 1; i++)
    if (a[i - 1] == a[i + 1] && a[i - 1] == 1 && !a[i]) b[i] = 1, c++;
  for (int i = 1; i < n - 1; i++)
    if (b[i - 1] == 1 && b[i + 1] == 1) {
      ans++, c--;
      a[i] = 0;
      b[i - 1] = 0;
      b[i + 1] = 0;
    }
  for (int i = 0; i < n; i++) ans += b[i];
  cout << ans;
  return 0;
}
