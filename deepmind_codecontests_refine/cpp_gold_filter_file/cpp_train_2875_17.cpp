#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  printf("%d %d", (n == k || !k) ? 0 : 1, n - k <= 2 * k ? n - k : 2 * k);
  return 0;
}
