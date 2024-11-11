#include <bits/stdc++.h>
using namespace std;
const int N = 100010 * 19;
int ch[N][2], s[N], l = 1, rt = 1;
map<long long, int> cnt;
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    char op[10];
    scanf("%s", op);
    long long a;
    scanf("%I64d", &a);
    if (op[0] == '+') {
      long long t = 0, tmp = 1;
      for (int i = 1; i <= 18; i++) t = t + (a & 1) * tmp, tmp *= 10, a /= 10;
      cnt[t]++;
    } else if (op[0] == '-') {
      long long t = 0, tmp = 1;
      for (int i = 1; i <= 18; i++) t = t + (a & 1) * tmp, tmp *= 10, a /= 10;
      cnt[t]--;
    } else if (op[0] == '?') {
      printf("%d\n", cnt[a]);
    }
  }
  return 0;
}
