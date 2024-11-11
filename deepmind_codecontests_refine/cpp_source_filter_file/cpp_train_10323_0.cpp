#include <bits/stdc++.h>
using namespace std;
int n, x, cnt1[101010], cnt2[101010], ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    cnt1[x]++;
    cnt2[cnt1[x]]++;
    if (cnt1[x] * cnt2[cnt1[x]] == i && i != n) {
      ans = i + 1;
    }
    if (cnt1[x] * cnt2[cnt1[x]] == i - 1) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
