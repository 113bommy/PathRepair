#include <bits/stdc++.h>
using namespace std;
int n, h;
int main() {
  scanf("%d %d", &n, &h);
  for (int i = 1; i < n; i++)
    printf("%.12lf%c", sqrt(1.0 * h / n), i < n - 1 ? ' ' : '\n');
  return 0;
}
