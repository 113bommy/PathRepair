#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string a, b;
  cin >> a >> b;
  long long cnt1 = 0, cnt2 = 0, cnt = 0;
  for (auto i : b) {
    if (i == '1') cnt1++;
  }
  int f1 = cnt1 % 2;
  long long m = b.size();
  for (long long i = 0; i < m; i++) {
    if (a[i] == '1') cnt2++;
  }
  if ((cnt2 % 2) == f1) cnt++;
  for (int i = 0; i < a.size() - m; i++) {
    if (a[i] == '1') cnt2 = cnt2 - 1;
    if (a[m + i] == '1') cnt2 = cnt2 + 1;
    if (cnt2 % 2 == f1) cnt++;
  }
  cout << cnt;
  return 0;
}
