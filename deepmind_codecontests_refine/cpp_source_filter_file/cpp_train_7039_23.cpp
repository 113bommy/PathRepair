#include <bits/stdc++.h>
using namespace std;
string sIn[1005];
int vistNum[1005];
int main() {
  long long L, R;
  long long l, r;
  long long ans;
  while (scanf("%I64d %I64d", &L, &R) != EOF) {
    ans = 0;
    l = 0;
    r = 999999999ll;
    for (long long i = 1; i <= 999999999ll; i = i * 10) {
      long long m = (i * 10 - 1) / 2;
      l = max(L, i);
      r = min(R, i * 10 - 1);
      if (l <= r) {
        if (m < l) m = l;
        if (m > r) m = r;
        ans = max(ans, m * (i * 10 - 1 - m));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
