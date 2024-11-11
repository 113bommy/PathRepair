#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long int INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 1e5 + 10;
int gcd(int first, int second) {
  return second == 0 ? first : gcd(second, first % second);
}
int lcm(int first, int second) { return first * second / gcd(first, second); }
int main() {
  int n, m, z;
  while (~scanf("%d%d%d", &n, &m, &z)) {
    printf("%d\n", z / lcm(n, m));
  }
  return 0;
}
