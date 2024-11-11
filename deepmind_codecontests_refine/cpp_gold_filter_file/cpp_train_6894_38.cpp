#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d %d", &m, &n);
    if (m % n == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
