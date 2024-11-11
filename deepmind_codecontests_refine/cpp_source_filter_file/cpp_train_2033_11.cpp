#include <bits/stdc++.h>
using namespace std;
const size_t MAX_N = (size_t)1e6 + 5;
int arr[MAX_N];
int main() {
  int n, q, t, x, even, odd;
  scanf("%d%d", &n, &q);
  even = 2;
  odd = 1;
  for (int i = 0; i < q; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &x);
      even += x;
      odd += x;
    } else {
      if (even & 1)
        even++;
      else
        even--;
      if (odd & 1)
        odd++;
      else
        odd--;
    }
    if (even < 0) even += n;
    if (odd < 0) odd += n;
    even %= n;
    odd %= n;
  }
  for (int i = 1; i <= n; i += 2) arr[(i + odd - 2) % n + 1] = i;
  for (int i = 2; i <= n; i += 2) arr[(i + even - 3) % n + 1] = i;
  for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
}
