#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  int n;
  scanf("%d", &n);
  if (n > 36) {
    printf("-1");
    return 0;
  }
  int temp1, temp2;
  temp1 = n / 2;
  temp2 = n % 2;
  for (int i = 0; i < temp1; i++) printf("8");
  if (temp2) printf("6");
}
