#include <bits/stdc++.h>
using namespace std;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;
int a, b, c, d;
int visited[10000];
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = b; i < 10000; i += a) {
    visited[i] = 1;
  }
  for (int i = d; i < 10000; i += c) {
    if (visited[i]) {
      printf("%d", i);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
