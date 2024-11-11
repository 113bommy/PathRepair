#include <bits/stdc++.h>
using namespace std;
int a[1050];
int n;
int minn = 919260817, maxn = 0;
int main() {
  cin >> n;
  for (int i(1); i <= n; i++) {
    scanf("%d", &a[i]);
    if (minn > a[i]) minn = a[i];
    if (maxn < a[i]) maxn = a[i];
  }
  int cz = maxn - minn + 1;
  printf("%d", cz - n);
  return 0;
}
