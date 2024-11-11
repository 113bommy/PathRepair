#include <bits/stdc++.h>
using namespace std;
const int MX = 25;
int main(int argc, char *argv[]) {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == m && n == 1)
    printf("%.12f\n", 1.);
  else
    printf("%.12f\n", (1.0 + (n - 1.) * (m - 1.) / (n * m - 1)) / n);
  return 0;
}
