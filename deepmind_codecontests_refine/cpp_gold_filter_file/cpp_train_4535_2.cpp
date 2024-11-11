#include <bits/stdc++.h>
char _;
using namespace std;
const int MAXN = 3e5;
int n, x[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  sort(x, x + n);
  printf("%d", x[n / 2 - !(n % 2)]);
}
