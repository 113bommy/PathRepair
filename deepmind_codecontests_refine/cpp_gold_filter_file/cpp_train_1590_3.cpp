#include <bits/stdc++.h>
using namespace std;
long long n, a[100005];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i <= n - 1; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = 1e15;
  long long now = 1;
  while (1) {
    int flag = 1;
    long long res = 0;
    long long ins = 1;
    res = res + abs(a[0] - 1);
    for (int i = 1; i <= n - 1; i++) {
      if (1e15 / now < ins) {
        flag = 0;
        break;
      }
      ins = ins * now;
      res = res + abs(a[i] - ins);
    }
    if (flag == 0) break;
    if (res >= 0) ans = ((ans) < (res) ? (ans) : (res));
    if (ins > 1e9) break;
    now++;
  }
  cout << ans << endl;
  return 0;
}
