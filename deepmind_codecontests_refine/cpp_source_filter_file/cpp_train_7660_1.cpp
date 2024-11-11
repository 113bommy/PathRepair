#include <bits/stdc++.h>
using namespace std;
int maxn = 1e9 + 9;
int a[200005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (maxn != 0) a[i] = maxn;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      int j = 1;
      while (a[i + j] != 0) a[i + j] = j, j++;
      i = i + j - 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] == 0) {
      int j = 1;
      while (a[i - j] != 0) a[i - j] = a[i - j] < j ? a[i - j] : j, j++;
      i = i - j + 1;
    }
  }
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
