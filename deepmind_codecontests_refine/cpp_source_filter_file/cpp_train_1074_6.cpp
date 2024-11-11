#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926536;
int a[105];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ans = n % 2 == 1 ? a[0] : 0;
  for (int i = n % 2 == 1 ? 2 : 1; i < n; i += 2)
    ans += a[i] * a[i] - a[i - 1] * a[i - 1];
  printf("%0.5f \n", ans * PI);
}
