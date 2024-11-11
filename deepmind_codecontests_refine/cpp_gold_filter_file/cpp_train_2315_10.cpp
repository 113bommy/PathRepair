#include <bits/stdc++.h>
using namespace std;
long long int dp[1000005][2];
int len;
char c[1000005];
long long int recur(long long int pos, long long int rev) {
  if (pos < 0) return rev;
  long long int &res = dp[pos][rev];
  if (res != -1) return res;
  if (rev) {
    if (c[pos] == '1') return res = recur(pos - 1, rev);
    return res = min(recur(pos - 1, rev) + 1, recur(pos - 1, 1 - rev) + 1);
  } else {
    if (c[pos] == '0') return res = recur(pos - 1, rev);
    return res = min(recur(pos - 1, rev) + 1, recur(pos - 1, 1 - rev) + 1);
  }
}
void print(char c, int num) { printf("%c2^%d\n", c, len - num - 1); }
int dump(long long int pos, long long int rev) {
  if (pos < 0) {
    if (rev) print('+', pos);
    return 0;
  }
  if (rev) {
    if (c[pos] == '1') return dump(pos - 1, rev);
    if (recur(pos - 1, rev) + 1 == dp[pos][rev]) {
      print('-', pos);
      return dump(pos - 1, rev);
    } else {
      print('+', pos);
      return dump(pos - 1, 1 - rev);
    }
  } else {
    if (c[pos] == '0') return dump(pos - 1, rev);
    if (recur(pos - 1, rev) + 1 == dp[pos][rev]) {
      print('+', pos);
      return dump(pos - 1, rev);
    } else {
      print('-', pos);
      return dump(pos - 1, 1 - rev);
    }
  }
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%s", c);
  len = strlen(c);
  printf("%d\n", (int)recur(len - 1, 0));
  dump(len - 1, 0);
}
