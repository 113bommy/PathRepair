#include <bits/stdc++.h>
using namespace std;
int n, a[1005], sol1[10], sol2[10];
bool check() {
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      return false;
    }
  }
  return true;
}
void dfs(int x) {
  if (check()) {
    cout << x - 1 << '\n';
    for (int i = 1; i < x; i++) {
      cout << sol1[i] << ' ' << sol2[i] << '\n';
    }
    exit(0);
  }
  if (x == 4) {
    return;
  }
  for (int i = 1; i < n; i++) {
    if ((a[i] != i) &&
        ((abs(a[i] - a[i - 1]) != 1) || (abs(a[i] - a[i + 1]) != 1))) {
      for (int j = i + 1; j <= n; j++) {
        if ((a[j] != j) &&
            ((abs(a[j] - a[j - 1]) != 1) || (abs(a[j] - a[j + 1]) != 1))) {
          reverse(a + i, a + j + 1);
          sol1[x] = i;
          sol2[x] = j;
          dfs(x + 1);
          reverse(a + i, a + j + 1);
        }
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  a[n + 1] = -1;
  dfs(1);
  return 0;
}
