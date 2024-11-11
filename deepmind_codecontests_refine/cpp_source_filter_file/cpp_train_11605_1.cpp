#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, m;
  cin >> a >> m;
  for (int i = 1; i <= m; i++) {
    if (a % m == 0) {
      printf("YES\n");
      return 0;
    } else {
      a += (a % m);
    }
  }
  printf("NO\n");
}
