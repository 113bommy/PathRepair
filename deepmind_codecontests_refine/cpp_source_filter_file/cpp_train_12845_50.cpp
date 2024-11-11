#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MAXN = 2002;
int A[MAXN];
int main() {
  scanf("%d,%d", &n, &k);
  double t = n * (n - 1) / 2;
  if (t <= k)
    printf("no solution");
  else {
    for (int i = 1; i <= n; i++) {
      cout << '0' << ' ' << i << endl;
    }
  }
}
