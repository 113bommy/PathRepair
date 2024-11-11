#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
char s[10];
void fmain() {
  scanf("%s", s + 1);
  long long x = (s[1] - '0') * 10000 + (s[3] - '0') * 1000 +
                (s[5] - '0') * 100 + (s[4] - '0') * 10 + (s[2] - '0');
  long long ans = 1;
  int mod = 100000;
  for (int(i) = 0; (i) < (int)(5); (i)++) ans = x * ans % mod;
  printf("%05lld\n", ans);
}
int main() {
  fmain();
  return 0;
}
