#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, a, b, cnt1, cnt2;
  cin >> n;
  string s;
  cin >> s;
  a = b = cnt1 = cnt2 = 0;
  for (long long int i = 0; i < n / 2; i++) {
    if (s[i] == '?')
      cnt1++;
    else
      a += (s[i] - '0');
  }
  for (long long int i = n / 2; i < n; i++) {
    if (s[i] == '?')
      cnt2++;
    else
      b += (s[i] - '0');
  }
  if (a < b) {
    swap(a, b);
    swap(cnt1, cnt2);
  }
  if (cnt1 > cnt2) {
    cout << "Monocarp" << '\n';
    return;
  } else {
    if ((a - b) <= ((cnt2 - cnt1) / 2) * 9)
      cout << "Bicarp" << '\n';
    else
      cout << "Monocarp" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
