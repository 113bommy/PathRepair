#include <bits/stdc++.h>
const int maxn = 0x3f3f3f3f;
const double EI =
    2.71828182845904523536028747135266249775724709369995957496696762772407663035354594571382178525166427;
const double PI = 3.141592653589793238462643383279;
using namespace std;
char c[110];
int main(void) {
  int t;
  long long z1 = 1, z2 = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", c);
    if (strcmp(c, "UL") == 0 || strcmp(c, "DR") == 0) {
      z1++;
    } else if (strcmp(c, "UR") == 0 || strcmp(c, "DL") == 0) {
      z2++;
    } else {
      z1++;
      z2++;
    }
  }
  printf("%lld\n", z1 * z2);
  return 0;
}
