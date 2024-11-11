#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  long long t = 0, flag = 0;
  long long a[105];
  scanf("%d", &n);
  t = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &t);
  }
  scanf("%d", &t);
  for (int i = 1; i <= n; i++) {
    if (a[i] > t) {
      cout << n - i + 1;
      return 0;
    }
  }
  cout << 1;
  return 0;
}
