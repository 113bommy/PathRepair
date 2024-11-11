#include <bits/stdc++.h>
using namespace std;
bool OK(char s[], char s1[]) {
  if (strlen(s) != strlen(s1)) return false;
  for (int i = 0; i < strlen(s); ++i)
    if (s[i] != s1[i]) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  bool b;
  long long int n, m, ans = 0, ans1 = 0;
  cin >> n >> m;
  long long int a[105], t[105] = {};
  char s[105][200];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
    b = true;
    for (int j = 0; j < i && b; ++j)
      if (OK(s[i], s[j])) {
        ++t[j];
        b = false;
        --m;
        --i;
      }
    if (b) ++t[i];
  }
  sort(t, t + m);
  for (int i = 0; i < n; ++i) {
    ans1 += t[m - i - 1] * a[n - i - 1];
    ans += t[m - i - 1] * a[i];
  }
  cout << ans << " " << ans1 << '\n';
}
