#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T x, T y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
template <class T>
T euclideanDistance(T x1, T x2, T y1, T y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
template <class T>
T digitSum(T n) {
  T sum = 0;
  while (n > 0) sum += n % 10, n /= 10;
  return sum;
}
const double INF = 1e+9;
const double INFLL = 1e+18;
const double EPS = 1e-9;
const double PI = acos(-1);
const int knightDir[8][2] = {{-2, -1}, {-2, 1}, {-1, 2},  {1, 2},
                             {2, -1},  {2, 1},  {-1, -2}, {1, -2}};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const long long int MOD = 1000000000 + 7;
int price[2000005] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int dp[2000005], lt[2000005], pos[2000005], ht[2000005], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &pos[i], &ht[i]);
  }
  dp[1] = 1;
  lt[1] = pos[1];
  for (int i = 2; i <= n; i++) {
    int temp = i == n ? INT_MAX : pos[i + 1];
    if (pos[i] - lt[i - 1] > ht[i]) {
      dp[i] = dp[i - 1] + 1;
      lt[i] = pos[i];
    } else if (pos[i] + ht[i] < temp) {
      dp[i] = dp[i - 1] + 1;
      lt[i] = pos[i] + ht[i];
    } else {
      dp[i] = dp[i - 1];
      lt[i] = max(pos[i], lt[i]);
    }
  }
  if (n == 2)
    printf("2\n");
  else
    printf("%d\n", dp[n]);
}
