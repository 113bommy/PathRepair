#include <bits/stdc++.h>
const int INF_INT = 0x3f3f3f3f;
const long long INF_LL = 0x7f7f7f7f;
const int MOD = 1e9 + 7;
const double eps = 1e-10;
const double pi = acos(-1);
using namespace std;
int n;
int num[5050];
int a[5050];
int ans[5050];
int main(int argc, char const *argv[]) {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
      memset(num, 0, sizeof(num));
      int tmp = 0, id = 0;
      for (int j = i; j <= n; j++) {
        num[a[j]]++;
        if (num[a[j]] > tmp || (num[a[j]] == tmp && a[j] < id)) {
          tmp = num[a[j]];
          id = a[j];
        }
        ans[id]++;
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}
