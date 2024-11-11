#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a;
  int res = 100;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if ((k % a) == 0) {
      if (res > (k / a)) res = k / a;
    }
  }
  cout << res;
  return 0;
}
