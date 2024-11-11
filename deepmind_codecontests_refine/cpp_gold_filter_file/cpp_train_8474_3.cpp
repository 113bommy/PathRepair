#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dX[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dY[] = {-1, -1, 0, 1, 1, 1, 0, -1};
char s[4010];
int a, n, v[4010];
int main(void) {
  scanf("%d %s", &a, s);
  n = strlen(s);
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) v[i] = (int)(s[i] - '0');
  map<int, long long> d;
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) {
    int c = 0;
    for (int((j)) = (0); ((j)) < ((n - i)); ((j))++) {
      c += v[i + j];
      d[c]++;
    }
  }
  long long r = 0;
  for (int x = 1; x * x <= a; x++)
    if (a % x == 0) {
      r += d[x] * d[a / x];
      if (x * x < a) r += d[a / x] * d[x];
    }
  if (a == 0)
    r = 2 * d[0] * (long long)n * (long long)(n + 1) / (long long)2 -
        d[0] * d[0];
  cout << r;
  return 0;
}
