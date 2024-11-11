#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n;
  for (int i = 1; i <= k; i++) printf("%d %d ", 2 * i, 2 * i - 1);
  for (int i = k + 1; i <= n; i++) printf("%d %d ", 2 * i - 1, 2 * i);
  return 0;
}
