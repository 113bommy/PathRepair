#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500;
const long long inf = 1e15 + 10;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  string s;
  int ans = 0, n;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    if (s[i] != s[i - 1]) ans++;
  cout << min(ans + 2, n) << '\n';
  return 0;
}
