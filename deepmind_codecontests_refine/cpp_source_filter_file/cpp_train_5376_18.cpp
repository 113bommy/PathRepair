#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;
int n, m;
int tab[N];
int main() {
  scanf("%d %d", &n, &m);
  if (m > 30) {
    printf("%d\n", n);
    return 0;
  }
  int x = 1;
  while (m--) x *= 2;
  printf("%d\n", n % x);
  return 0;
}
