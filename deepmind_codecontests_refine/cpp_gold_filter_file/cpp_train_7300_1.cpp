#include <bits/stdc++.h>
using namespace std;
const int N = 444;
int n;
int a[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  int ans = -1;
  for (int i = 1; i < n; ++i)
    for (int j = i; j < n; ++j) {
      int value = a[i - 1] - 1, best = 1;
      for (int k = i; k <= j; ++k) {
        best += value / a[k];
        value %= a[k];
      }
      int tValue = value = a[i - 1] - 1 - value + a[j];
      int greedy = 0;
      for (int k = 0; k < n; ++k) {
        greedy += value / a[k];
        value %= a[k];
      }
      if (greedy > best && (ans == -1 || tValue < ans)) ans = tValue;
    }
  printf("%d\n", ans);
}
