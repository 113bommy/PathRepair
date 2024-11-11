#include <bits/stdc++.h>
using namespace std;
int x[100], y[100];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (x[i] + y[i] == x[j] && x[j] + y[j] == x[i]) {
        printf("YES\n");
        return 0;
      }
  printf("NO\n");
  return 0;
}
