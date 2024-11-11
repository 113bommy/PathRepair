#include <bits/stdc++.h>
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1123456;
const long long MOD = 1123456769;
using namespace std;
int n, a[MAXN];
void check() {
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) return;
  for (int i = 2; i <= n; i++)
    if (a[i] < a[i - 1]) return;
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  srand(time(0));
  int m, k, i, j, x;
  cin >> n >> m >> k;
  for (j = 1; j <= m; j++) {
    cin >> x;
    if (x <= (k + 1) / 2) {
      for (i = 1; i <= n; i++)
        if (a[i] == 0 || a[i] > x) {
          a[i] = x;
          cout << i << endl;
          break;
        }
    } else {
      for (i = n; i >= 1; i--)
        if (a[i] == 0 || a[i] < x) {
          a[i] = x;
          cout << i << endl;
          break;
        }
    }
    check();
  }
  return 0;
}
