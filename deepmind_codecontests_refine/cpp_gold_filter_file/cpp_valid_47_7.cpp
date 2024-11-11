#include <bits/stdc++.h>
using namespace std;
long long a[1005];
char op[] = "and";
char op2[] = "or";
char op3[] = "finish";
int n, k;
void solve() {
  int f = 0;
  int num = 0;
  int m = n / 3;
  int x = 1;
  vector<int> res;
  int s = 1;
  while (num < 6 * m) {
    int sum1, sum2, sum3;
    int x, y, z;
    printf("%s %d %d\n", op, s, s + 1);
    fflush(stdout);
    scanf("%d", &x);
    printf("%s %d %d\n", op2, s, s + 1);
    fflush(stdout);
    scanf("%d", &sum1);
    sum1 += x;
    printf("%s %d %d\n", op, s + 1, s + 2);
    fflush(stdout);
    scanf("%d", &y);
    printf("%s %d %d\n", op2, s + 1, s + 2);
    fflush(stdout);
    scanf("%d", &sum2);
    sum2 += y;
    printf("%s %d %d\n", op, s, s + 2);
    fflush(stdout);
    scanf("%d", &z);
    printf("%s %d %d\n", op2, s, s + 2);
    fflush(stdout);
    scanf("%d", &sum3);
    sum3 += z;
    y = sum1 + sum2 - sum3;
    y /= 2;
    x = sum1 - y;
    z = sum3 - x;
    res.push_back(x);
    res.push_back(y);
    res.push_back(z);
    num += 6;
    s += 3;
    fflush(stdout);
  }
  if (m * 3 < n) {
    for (int i = m * 3 + 1; i <= n; i++) {
      int g = res[res.size() - 1];
      int x, y;
      printf("%s %d %d\n", op, i - 1, i);
      fflush(stdout);
      scanf("%d", &x);
      printf("%s %d %d\n", op2, i - 1, i);
      fflush(stdout);
      scanf("%d", &y);
      x += y;
      res.push_back(x - g);
      fflush(stdout);
    }
  }
  sort(res.begin(), res.end());
  int g = res[k - 1];
  printf("%s %d\n", op3, g);
}
int main() {
  cin >> n >> k;
  solve();
  return 0;
}
