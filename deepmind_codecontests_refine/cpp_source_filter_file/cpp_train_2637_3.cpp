#include <bits/stdc++.h>
using namespace std;
int a[10] = {0}, n, i, taxi = 0;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &i);
    a[i]++;
  }
  if (a[3] != 0) a[1] = a[1] - min(a[1], a[3]);
  if (a[1] + 2 * a[2] % 4 == 0)
    taxi = a[4] + a[3] + (2 * a[2] + a[1]) / 4;
  else
    taxi = a[4] + a[3] + (2 * a[2] + a[1]) / 4 + 1;
  cout << taxi;
}
