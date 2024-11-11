#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  if (m > n) swap(n, m);
  if (m == 1)
    printf("%d\n", n);
  else if (m == 2)
    printf("%d\n", n / 4 * 4 + (n % 4 == 3 ? 4 : n % 4 * 2));
  else
    printf("%d\n", (n * m + 1) / 2);
}
