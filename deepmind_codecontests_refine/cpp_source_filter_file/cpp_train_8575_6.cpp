#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k > n)
    printf("-1");
  else if (n == 1) {
    if (k == 1)
      printf("a");
    else
      printf("-1");
  } else if (n == 2)
    printf("ab");
  else {
    string res = "";
    int ost = n - k + 2;
    for (int i = 0; (i) < (ost); (i)++) {
      if (i % 2 == 0)
        res += 'a';
      else
        res += 'b';
    }
    for (int i = 2; i < k; i++) res += ('a' + i);
    cout << res;
  }
  return 0;
}
