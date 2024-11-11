#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n, nowp;
string ans;
long long f[maxn][2][2][2], k;
long long dfs(int length, bool is_minest, bool flag2, bool flag3) {
  int l = length;
  int r = n - length + 1;
  if (l > r) {
    if (flag2 == false && flag3)
      return 0;
    else
      return 1;
  }
  long long &v = f[length][is_minest][flag2][flag3];
  if (v) return v;
  for (int a = 0; a <= 1; a++)
    if (!(l <= nowp && ans[l - 1] != '0' + a)) {
      for (int b = 0; b <= 1; b++)
        if (!(r <= nowp && ans[r - 1] != '0' + b)) {
          if (l == r && a != b) continue;
          if (!is_minest && a > b) continue;
          if (!flag2 && a + b > 1) continue;
          bool is_minest1, flag22, flag33;
          if (a < b)
            is_minest1 = true;
          else
            is_minest1 = is_minest;
          if (a + b < 1)
            flag22 = true, flag33 = false;
          else {
            flag22 = flag2;
            if (a + b > 1)
              flag33 = true;
            else
              flag33 = flag3;
          }
          v += dfs(length + 1, is_minest1, flag22, flag33);
        }
    }
  return v;
}
int main() {
  scanf("%d%I64d", &n, &k);
  k++;
  ans = "";
  for (int a = 1; a <= n; a++) {
    ans = ans + "0";
    memset(f, 0, sizeof(f));
    nowp = a;
    long long rank = dfs(1, 0, 0, 0);
    if (rank >= k) continue;
    if (a == 1) {
      printf("-1\n");
      return 0;
    }
    ans[a - 1] = '1';
    k -= rank;
  }
  cout << ans << endl;
  return 0;
}
