#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int h1[100110], h2[100110], h[100110];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  int ans = 0;
  h1[0] = 0;
  for (int i = 1; i <= n; ++i) h1[i] = min(h[i], h[i - 1] + 1);
  h2[n + 1] = 0;
  for (int i = n; i >= 1; --i) h2[i] = min(h[i], h2[i + 1] + 1);
  for (int i = 1; i <= n; ++i) ans = max(ans, min(h1[i], h2[i]));
  cout << ans << endl;
  return 0;
}
