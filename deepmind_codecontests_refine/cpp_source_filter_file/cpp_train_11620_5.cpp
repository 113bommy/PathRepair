#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int dp[2][200][200];
int n, k;
int a[200];
int pw5(int num) {
  int cnt = 0;
  while (num % 5 == 0) {
    cnt++;
    num /= 5;
  }
  return cnt;
}
int pw2(int num) {
  int cnt = 0;
  while (num % 2 == 0) {
    num /= 2;
    cnt++;
  }
  return cnt;
}
int f[205][5005];
int main(int argc, char* argv[]) {
  cin >> n >> k;
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    int x = 0, y = 0;
    while (a % 2 == 0) a /= 2, x++;
    while (a % 5 == 0) a /= 5, y++;
    for (int j = k - 1; j >= 0; j--) {
      for (int l = 0; l < 5000; l++) {
        if (f[j][l] + 1) f[j + 1][l + y] = max(f[j + 1][l + y], f[j][l] + x);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 5000; i++) ans = max(ans, min(i, f[k][i]));
  cout << ans;
  return 0;
}
