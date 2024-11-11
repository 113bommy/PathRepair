#include <bits/stdc++.h>
using namespace std;
struct pair {
  int a;
  int b;
};
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int dp[1000001];
  for (int i = 0; i < 1000001; i++) {
    dp[i] = 1;
  }
  for (int i = 1; i <= 1000000; i++) {
    for (int e = i + i; e < 1000000; e += i) {
      dp[e]++;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= a; i++) {
    for (int e = 1; e <= b; e++) {
      for (int j = 1; j <= c; j++) {
        ans += (dp[i * e * j]) % 1073741824;
      }
    }
  }
  cout << ans;
}
