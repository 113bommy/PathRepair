#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 5;
int main() {
  int n, a;
  int i, ans;
  int bian[N];
  double jiao, jaio2, tmp, minjiao;
  while (~scanf("%d%d", &n, &a)) {
    ans = 3;
    jiao = (double)180.0 * (n - 2) / n;
    tmp = (180 - jiao) / 2;
    minjiao = (double)jiao / (n - 2);
    for (i = 4; i <= n; i++) {
      if (fabs((180 - jiao) * (i - 2) / 2 - a) < fabs(tmp - a)) {
        tmp = (180 - jiao) * (i - 2) / 2;
        ans = i;
      }
    }
    cout << "2 1 " << ans << endl;
  }
}
