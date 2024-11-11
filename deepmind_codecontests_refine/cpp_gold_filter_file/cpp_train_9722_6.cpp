#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  char a[100010], b[100010];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  bool large = false;
  bool less = false;
  int total = 0;
  int com = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '?') total++;
    if (b[i] == '?') total++;
    if (a[i] == '?' && b[i] == '?') com++;
    if (a[i] != '?' && b[i] != '?') {
      if (a[i] < b[i]) less = true;
      if (a[i] > b[i]) large = true;
    }
  }
  long long ans = 1;
  for (int i = 0; i < total; i++) ans = (ans * 10) % 1000000007;
  if (large && less) {
    cout << ans << endl;
    return 0;
  }
  long long c1 = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == '?' && b[i] == '?') {
      c1 = (c1 * 55) % 1000000007;
      continue;
    }
    if (a[i] == '?') {
      c1 = (c1 * (10 - (b[i] - '0'))) % 1000000007;
      continue;
    }
    if (b[i] == '?') {
      c1 = (c1 * (a[i] - '0' + 1)) % 1000000007;
      continue;
    }
  }
  if (large) {
    ans = (ans + 1000000007 - c1) % 1000000007;
    cout << ans << endl;
    return 0;
  }
  long long c2 = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == '?' && b[i] == '?') {
      c2 = (c2 * 55) % 1000000007;
      continue;
    }
    if (a[i] == '?') {
      c2 = (c2 * (b[i] - '0' + 1)) % 1000000007;
      continue;
    }
    if (b[i] == '?') {
      c2 = (c2 * (10 - (a[i] - '0'))) % 1000000007;
      continue;
    }
  }
  if (less) {
    ans = (ans + 1000000007 - c2) % 1000000007;
    cout << ans << endl;
    return 0;
  }
  if (!large && !less) {
    long long c3 = 1;
    for (int i = 0; i < com; i++) c3 = (c3 * 10) % 1000000007;
    ans = (ans + 1000000007 - c1 - c2 + c3) % 1000000007;
    cout << ans << endl;
    return 0;
  }
  return 0;
}
