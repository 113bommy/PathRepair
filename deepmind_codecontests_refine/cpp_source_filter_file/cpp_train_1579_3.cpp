#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    cnt1 += (k == 1);
    cnt2 += (k == 2);
  }
  if (!cnt1 || !cnt2) {
    for (int i = 0; i < cnt1; i++) cout << 1 << ' ';
    for (int i = 0; i < cnt2; i++) cout << 2 << ' ';
  } else {
    cout << 1 << ' ';
    cout << 2 << ' ';
    for (int i = 0; i < cnt2 - 1; i++) cout << 2 << ' ';
    for (int i = 0; i < cnt1 - 1; i++) cout << 1 << ' ';
  }
}
