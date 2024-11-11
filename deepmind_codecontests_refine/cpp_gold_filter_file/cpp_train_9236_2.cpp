#include <bits/stdc++.h>
using namespace std;
int x[107];
int v1, v2, xu, yu;
double cal(int x) {
  double dis = sqrt(1.0 * (xu - x) * (xu - x) + 1.0 * yu * yu);
  double ans = 1.0 * x / v1 + dis / v2;
  return ans;
}
int main() {
  int n;
  scanf("%d%d%d", &n, &v1, &v2);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }
  scanf("%d%d", &xu, &yu);
  double minn = cal(x[2]);
  int pos = 2;
  for (int i = 3; i <= n; i++) {
    if (cal(x[i]) <= minn) {
      minn = cal(x[i]);
      pos = i;
    }
  }
  printf("%d\n", pos);
  return 0;
}
