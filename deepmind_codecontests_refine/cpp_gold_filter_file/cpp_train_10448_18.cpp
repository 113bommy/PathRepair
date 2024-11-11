#include <bits/stdc++.h>
using namespace std;
long long pre[105][105];
void preCalc() {
  for (int i = 1; i <= 100; i++) {
    long long temp = i;
    for (int j = 2; j <= temp; j++) {
      long long x = 0;
      while (temp % j == 0) {
        x++;
        temp /= j;
      }
      pre[i][j] = x;
    }
  }
}
int main() {
  preCalc();
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        long long here = 1;
        for (int l = 2; l <= 100; l++) {
          long long temp = pre[i][l] + pre[j][l] + pre[k][l];
          here = (here * (temp + 1)) & ((1LL << 30) - 1);
        }
        ans = (ans + here) & ((1LL << 30) - 1);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
