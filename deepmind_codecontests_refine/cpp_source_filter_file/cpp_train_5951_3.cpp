#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  if (a[1] == a[n >> 1 | 1])
    printf("Bob");
  else
    printf("Elice");
  return 0;
}
