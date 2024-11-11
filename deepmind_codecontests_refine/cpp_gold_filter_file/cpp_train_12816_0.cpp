#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int main() {
  cin >> n >> m;
  long long z = 0;
  for (int i = (0); i < (n); i++) {
    scanf("%d", &a[i]);
    z += a[i];
  }
  sort(a, a + n);
  int top = a[n - 1];
  int ta = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (top == 1) break;
    ta++;
    if (top > a[i])
      top = a[i];
    else
      top--;
  }
  printf("%lld", z - (n + a[n - 1] - 1 - ta));
  return 0;
}
