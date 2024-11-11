#include <bits/stdc++.h>
using namespace std;
int a[300];
int main() {
  int n;
  double aver, s2;
  double s;
  scanf("%d", &n);
  while (n--) {
    aver = 0.0;
    s2 = 0.0;
    for (int i = 0; i < 250; i++) {
      scanf("%d", &a[i]);
      aver += a[i];
    }
    aver = aver / 250.0;
    for (int i = 0; i < 250; i++) {
      s2 += (a[i] - aver) * (a[i] - aver);
    }
    s2 = s2 / 250.0;
    int cnt = 0;
    if (fabs(1 - (s2 / aver)) < 0.10)
      printf("poisson\n");
    else
      printf("uniform\n");
  }
}
