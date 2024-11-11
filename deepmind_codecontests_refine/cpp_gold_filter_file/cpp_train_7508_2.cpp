#include <bits/stdc++.h>
using namespace std;
inline bool pal(const string& a, int l, int r) {
  for (int i = l, j = r; i < j; i++, j--) {
    if (a[i] != a[j]) return false;
  }
  return true;
}
inline bool isSame(const string& a, int l, int r) {
  if (l == r) return true;
  char t = a[l];
  size_t cnt = 0;
  for (int i = l; i <= r; i++) {
    if (a[i] == t) cnt++;
  }
  return ((r - l + 1) & 1) ? cnt >= a.size() - 1 : cnt == a.size();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string a;
  cin >> a;
  int n = a.size();
  if (isSame(a, 0, n - 1)) {
    puts("Impossible");
    return 0;
  }
  int ans = 2;
  for (int i = 1; i < n; i += 2) {
    if (pal(a, 0, i) && pal(a, i + 1, n - 1)) {
      if (a.substr(0, (i + 1) / 2) != a.substr((i + 1) / 2, (i + 1) / 2)) {
        ans = 1;
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
