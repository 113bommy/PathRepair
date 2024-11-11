#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
pair<int, int> s[N];
int a[N], b[N];
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i].first, s[i].second = i;
  sort(s, s + n);
  cout << "YES\n";
  int i;
  for (i = 0; i < n / 3; ++i)
    a[s[i].second] = i, b[s[i].second] = s[i].first - i;
  for (; i < (2 * n / 3); ++i)
    b[s[i].second] = i, a[s[i].second] = s[i].first - i;
  for (int j = n - i - 1; i < n; ++i, --j)
    b[s[i].second] = j, a[s[i].second] = s[i].first - j;
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; ++i) cout << b[i] << ' ';
  cout << '\n';
  return 0;
}
