#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 2e5 + 2;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    if (n % m == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
