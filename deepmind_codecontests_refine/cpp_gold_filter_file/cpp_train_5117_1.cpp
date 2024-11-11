#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
char input[maxn];
int main() {
  scanf("%s", input);
  {
    int length = strlen(input);
    char a = input[0];
    bool st = (a == 'A' || a == 'E' || a == 'F' || a == 'H' || a == 'I' ||
               a == 'K' || a == 'L' || a == 'M' || a == 'N' || a == 'T' ||
               a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == 'Z');
    for (int i = 1; i < length; i++) {
      char a = input[i];
      if ((a == 'A' || a == 'E' || a == 'F' || a == 'H' || a == 'I' ||
           a == 'K' || a == 'L' || a == 'M' || a == 'N' || a == 'T' ||
           a == 'V' || a == 'W' || a == 'X' || a == 'Y' || a == 'Z')) {
        if (!st) {
          printf("NO\n");
          return 0;
        }
      } else {
        if (st) {
          printf("NO\n");
          return 0;
        }
      }
    }
    printf("YES\n");
  }
  return 0;
}
