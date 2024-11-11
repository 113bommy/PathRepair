#include <bits/stdc++.h>
using namespace std;
int ON(int N, int pos) { return N = N | (1 << pos); }
int OFF(int N, int pos) { return N = N & ~(1 << pos); }
bool isON(int N, int pos) { return (bool)(N & (1 << pos)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc, cs;
  int i, j, k;
  int n;
  while (cin >> n >> k) {
    int a[105];
    for (i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (i = 0; i < n / k; i++) {
      int o = 0, t = 0;
      for (j = i; j < n; j += k) {
        if (a[j] == 1)
          o++;
        else
          t++;
      }
      ans += min(o, t);
    }
    cout << ans << endl;
  }
  return 0;
}
