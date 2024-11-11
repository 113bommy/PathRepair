#include <bits/stdc++.h>
using namespace std;
int n, t[110], T, num[2100], ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 0; i < n; i++) num[t[i]]++;
  for (int i = 1; i < 2100; i++) num[i] += num[i - 1];
  cin >> T;
  for (int i = 1; i <= 1010; i++) ans = max(ans, num[T + i] - num[i - 1]);
  cout << ans << endl;
  return 0;
}
