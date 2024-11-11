#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
int n;
int T[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &T[i]);
  sort(T + 1, T + n + 1);
  n /= 2;
  printf("%d\n", T[n]);
  return 0;
}
