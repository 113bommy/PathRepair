#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
string s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> s;
    cin >> a >> b;
    if (a > b && a >= 2400) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
