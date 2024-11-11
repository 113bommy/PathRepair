#include <bits/stdc++.h>
using namespace std;
int n, k;
int mark[10000000];
void getMark(int number) {
  int cnt = 0;
  for (int i = 0; i <= number; i++) mark[i] = i;
  for (int i = 2; i <= number; i++) {
    if (mark[i] == i) {
      for (int j = i * 2; j <= number; j += i) mark[j] = i;
    }
  }
}
int dp[10000000];
int c[6001][6001];
void buildC(int number) {
  for (int i = 0; i <= number; i++) {
    c[i][1] = i;
    c[i][0] = 1;
  }
  for (int i = 2; i <= number; i++)
    for (int j = 1; j <= number; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
}
int ji(int i, int j) {
  int sum = 0;
  for (int t = j; t >= 0; t--) {
    sum = (sum + c[i - t][j - t]) % 1000000007;
  }
  return sum;
}
int sou(int i) {
  int m = i;
  int ans = 1;
  while (m != 1) {
    int tmp = mark[m], t = 1;
    m /= tmp;
    while (mark[m] == tmp) {
      t++;
      m /= tmp;
    }
    ans = ans * ji(t + k - 2, t) % 1000000007;
  }
  return (int)ans;
}
int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("%d\n", n);
    return 0;
  }
  getMark(4000);
  buildC(6000);
  dp[1] = 1;
  int sum = 1;
  for (int i = 2; i <= n; i++) {
    sum = (sum + sou(i)) % 1000000007;
  }
  printf("%d\n", sum);
}
