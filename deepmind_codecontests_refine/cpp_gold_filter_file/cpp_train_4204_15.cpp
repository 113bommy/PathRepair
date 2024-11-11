#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[105];
  scanf(
      "%"
      "d",
      &n);
  for (int i = 0; i < n; i++)
    scanf(
        "%"
        "d",
        &a[i]);
  int max = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int maxor = 0;
      for (int k = i; k <= j; k++) {
        maxor = maxor ^ a[k];
      }
      if (maxor > max) max = maxor;
    }
  }
  cout << max;
  return 0;
}
