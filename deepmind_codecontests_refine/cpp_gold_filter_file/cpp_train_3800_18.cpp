#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n, num;
  scanf("%d%d", &n, &num);
  int res = 0;
  for (int i = 1; i * i <= num; i++) {
    if (!(num % i)) {
      if (i <= n && num / i <= n) {
        res++;
        if (i != num / i) res++;
      }
    }
  }
  printf("%d", res);
}
