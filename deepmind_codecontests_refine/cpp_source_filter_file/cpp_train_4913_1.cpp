#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
pair<int, int> a[N];
char s[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
  sort(a, a + n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= n; ++j)
      s[(i + j) % (n + 1)][a[i].second] = '0' + (j < a[i].first);
  cout << n + 1 << '\n';
  for (int i = 0; i <= n; ++i) cout << s[i] << '\n';
  return 0;
}
