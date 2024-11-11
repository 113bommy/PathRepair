#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long cnt1[11];
  unsigned long long cnt2[11];
  memset(cnt1, 0, sizeof(cnt1));
  memset(cnt2, 0, sizeof(cnt2));
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 0)
      cnt1[x]++;
    else
      cnt2[-x]++;
  }
  unsigned long long ret = 0;
  for (int i = 1; i < 10; i++) ret += cnt2[i] * cnt1[i];
  ret += cnt1[0] * (cnt1[0] - 1) / 2;
  cout << ret << endl;
  return 0;
}
