#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
map<int, int> p;
long long dp[17000][600];
void init() {
  dp[0][0] = 1;
  for (int i = 1; i < 17000; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= 500; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      dp[i][j] %= 1000000007;
    }
  }
}
int main() {
  int n;
  cin >> n;
  init();
  p.clear();
  for (int i = 1; i <= n; i++) {
    int temp;
    scanf("%d", &temp);
    int t = sqrt(temp);
    for (int j = 2; j <= t; j++) {
      if (temp % j == 0) {
        while (temp % j == 0) {
          temp = temp / j;
          p[j]++;
        }
      }
    }
    if (temp != 1) p[temp]++;
  }
  long long sum = 1;
  map<int, int>::iterator it;
  for (it = p.begin(); it != p.end(); it++) {
    int temp = it->second;
    int x = temp + n - 1;
    sum = sum * dp[x][n - 1];
    sum = sum % 1000000007;
  }
  cout << sum << endl;
  return 0;
}
