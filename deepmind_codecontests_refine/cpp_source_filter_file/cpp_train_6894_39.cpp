#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d %d", &m, &n);
    if (n % m == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
