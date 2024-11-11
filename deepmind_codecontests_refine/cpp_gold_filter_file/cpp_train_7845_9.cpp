#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%i", &t);
  bool used[180];
  memset(used, false, sizeof used);
  for (int n = 3; n <= 360; n++) {
    long long up = (n - 2) * 180;
    if (up % n == 0) {
      used[up / n] = true;
    }
  }
  for (int i = 0; i < t; i++) {
    int tmp;
    scanf("%i", &tmp);
    if (used[tmp])
      printf("YES");
    else
      printf("NO");
    printf("\n");
  }
  return 0;
}
