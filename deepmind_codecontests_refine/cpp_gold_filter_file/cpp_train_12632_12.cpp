#include <bits/stdc++.h>
using namespace std;
const int BASE = 10000;
int dp[5020][1010];
int x[2010][1010];
int v[1010];
void add(int a[], int len, int b[]) {
  for (int i = len - 1, carry = 0; i >= 0; --i) {
    carry = carry + a[i] + b[i];
    a[i] = carry % BASE;
    carry = carry / BASE;
  }
}
bool cmp(int a[], int len, int b[]) {
  for (int i = 0; i < len; i++) {
    if (a[i] < b[i])
      return 1;
    else if (b[i] < a[i])
      return 0;
  }
  return 2;
}
map<int, int> ma;
int main() {
  int n, i, j, m;
  string s;
  memset(x, 0, sizeof(x));
  x[0][999] = 1;
  for (i = 1; i <= 2000; i++) {
    memcpy(x[i], x[i - 1], sizeof(x[i - 1]));
    add(x[i], 1000, x[i - 1]);
  }
  while (cin >> n) {
    memset(dp, 0, sizeof(0));
    for (i = 1; i <= n; i++) {
      cin >> s >> m;
      memcpy(dp[i], dp[i - 1], sizeof(dp[i - 1]));
      if (s == "win") {
        ma[m] = i;
      } else {
        if (ma[m] > 0) {
          memcpy(v, dp[ma[m]], sizeof(dp[ma[m]]));
          add(v, 1000, x[m]);
          if (cmp(dp[i], 1000, v)) {
            memcpy(dp[i], v, sizeof(v));
          }
        }
      }
    }
    for (i = 0; i < 1000; i++) {
      if (dp[n][i]) {
        printf("%d", dp[n][i]);
        break;
      }
    }
    if (i >= 1000) cout << "0";
    for (i++; i < 1000; i++) {
      printf("%04d", dp[n][i]);
    }
    printf("\n");
  }
  return 0;
}
