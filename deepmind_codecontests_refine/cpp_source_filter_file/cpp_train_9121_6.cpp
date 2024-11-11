#include <bits/stdc++.h>
using namespace std;
const char s[4][100] = {"What are you doing while sending \"",
                        "\"? Are you busy? Will you send \"", "\"?",
                        "What are you doing at the end of the world? Are you "
                        "busy? Will you save us?"};
long long c[100010] = {75};
char dfs(int n, long long x) {
  if (x > c[n]) return '.';
  if (n == 0) return s[3][x - 1];
  if (x <= 34)
    return s[0][x - 1];
  else if (x <= 34 + c[n - 1])
    return dfs(n - 1, x - 34);
  else if (x <= 34 + c[n - 1] + 32)
    return s[1][x - 34 - c[n - 1] - 1];
  else if (x <= 34 + c[n - 1] + 32 + c[n - 1])
    return dfs(n - 1, x - 34 - c[n - 1] - 32);
  return s[2][x - 34 + c[n - 1] + 32 + c[n - 1] - 1];
}
int main() {
  long long b;
  int n, a;
  ios::sync_with_stdio(false);
  for (int i = 1; i <= 53; i++) c[i] = c[i - 1] * 2 + 68;
  for (int i = 54; i <= 100000; i++) c[i] = c[i - 1];
  cin >> n;
  while (n--) {
    cin >> a >> b;
    putchar(dfs(a, b));
  }
  return 0;
}
