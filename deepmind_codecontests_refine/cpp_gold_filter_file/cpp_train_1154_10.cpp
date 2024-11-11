#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int mod = 1e9 + 7;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    num += x;
    printf("%d ", num / m);
    num %= m;
  }
  printf("\n");
  return 0;
}
