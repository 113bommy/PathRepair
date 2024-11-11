#include <bits/stdc++.h>
using namespace std;
int n;
bool f, a[(int)1e6 + 9];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < (n == 3 ? 2 : (n >> 1)); i++) {
    if (n % i == 0) {
      for (int j = 0; j < i; j++) {
        if (!a[i]) continue;
        int k = j + i;
        f = 1;
        while (k != j) {
          if (!a[k]) {
            f = 0;
            break;
          }
          k = (k + i) % n;
        }
        if (f) break;
      }
      if (f) break;
    }
  }
  if (f)
    printf("YES");
  else
    printf("NO");
  return 0;
}
