#include <bits/stdc++.h>
using namespace std;
const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
const int MXN = 1000010;
const int C = 262144;
const int INF = 1000000001;
long long int gcd(long long int x, long long int y) {
  long long int tmp;
  while (y) {
    tmp = x;
    x = y;
    y = tmp % y;
  }
  return x;
}
void solve(long long int x, long long int y) {
  if (x == 0 || y == 0) return;
  if (x == 1)
    printf("%lldB", y - 1);
  else if (y == 1)
    printf("%lldA", x - 1);
  else if (x > y) {
    printf("%lldA", x / y);
    solve(x % y, y);
  } else if (y > x) {
    printf("%lldB", y / x);
    solve(x, y % x);
  }
}
void test() {
  long long int x, y;
  cin >> x >> y;
  if (gcd(x, y) != 1) {
    printf("Impossible\n");
    return;
  } else
    solve(x, y);
  printf("\n");
}
int main() {
  int te = 1;
  while (te--) test();
  return 0;
}
