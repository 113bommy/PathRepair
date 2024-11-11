#include <bits/stdc++.h>
long long MOD = 1e9 + 7;
using namespace std;
void print(int x, int y) {
  printf("%d %d\n", x, y);
  return;
}
int main() {
  int n, x;
  cin >> n >> x;
  int a[600010];
  for (int i = 0; i < n; i++) cin >> a[i];
  int m, y;
  cin >> m >> y;
  int b[600010];
  for (int i = 0; i < m; i++) cin >> b[i];
  int ans = 0;
  for (int iii = 0; iii < 31; iii++) {
    long long t = pow(2, iii);
    t *= 2;
    map<int, int> ma;
    int ss = 0;
    for (int i = 0; i < n; i++) {
      ma[(a[i] % t + t) % t]++;
      ss = max(ss, ma[(a[i] % t + t) % t]);
    }
    for (int i = 0; i < m; i++) {
      ma[(b[i] % t + t + t / 2) % t]++;
      ss = max(ss, ma[(b[i] % t + t + t / 2) % t]);
    }
    ans = max(ans, ss);
  }
  cout << ans;
}
