#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t[100100], h[100100];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }
  h[0] = h[n - 1] = 1;
  for (int i = 1; i < n - 1; ++i) {
    if (t[i] > t[i - 1])
      h[i] = h[i - 1] + 1;
    else
      h[i] = t[i];
  }
  for (int i = n - 1; i >= 0; --i) {
    if (t[i] > t[i + 1])
      h[i] = min(h[i], h[i + 1] + 1);
    else
      h[i] = min(h[i], t[i]);
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    result = max(result, h[i]);
  }
  printf("%d\n", result);
  return 0;
}
