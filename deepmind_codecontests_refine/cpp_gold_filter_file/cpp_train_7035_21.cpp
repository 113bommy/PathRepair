#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int l, r, ans = -1, a[20000000], a2[2000000], n, mid;
bool ch(int mid) {
  for (int i = 0; i < n; i++) a2[i] = 0;
  for (int i = 0; i <= mid; i++) a2[a[i]] = 1;
  int j = 0, i = 0;
  while (i < n) {
    if (s1[i] == s2[j] && a2[i] == 0) {
      i++;
      j++;
    } else
      i++;
    if (j == s2.size()) return 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s1 >> s2;
  n = s1.size();
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  l = 0;
  r = n;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (ch(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  cout << ans + 1;
  return 0;
}
