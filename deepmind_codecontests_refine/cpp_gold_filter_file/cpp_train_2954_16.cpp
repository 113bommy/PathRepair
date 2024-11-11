#include <bits/stdc++.h>
using namespace std;
int last[1000001], last2[1000001], sg[1000001], hash[1000001];
long long pos[101], sg2[101];
int main() {
  long long n, i, j, k, a, b;
  scanf("%I64d", &n);
  long long asg = 0;
  for (i = 1; i <= n; ++i) {
    scanf("%I64d", &a);
    if (a >= 4)
      if (a < 16)
        asg ^= 1;
      else if (a < 82)
        asg ^= 2;
      else if (a >= 6724)
        if (a < 50626)
          asg ^= 3;
        else if (a < 2562991876ll)
          asg ^= 1;
        else
          asg ^= 2;
  }
  if (asg)
    printf("Furlo\n");
  else
    printf("Rublo\n");
  return 0;
}
