#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int cnt;
  for (int i = 0; i <= 35; i++) {
    for (int j = 0; j <= 35; j++) {
      long long ans = pow(2, i) * pow(3, j);
      if (ans >= n and ans <= m) cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
