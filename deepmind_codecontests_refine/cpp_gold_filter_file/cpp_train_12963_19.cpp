#include <bits/stdc++.h>
using namespace std;
const int ma = 100000;
const int mb = 1;
const int maxn = mb + ma;
int da[2][400];
int main() {
  int n;
  char s;
  int a, b, c;
  cin >> n;
  memset(da, 0, sizeof(da));
  for (int i = 0; i < n; i++) {
    cin >> s >> a >> b;
    c = (s == 'M' ? 0 : 1);
    for (int j = a; j <= b; j++) da[c][j]++;
  }
  int sum = 0;
  for (int i = 1; i <= 366; i++) sum = max(sum, min(da[0][i], da[1][i]) * 2);
  printf("%d", sum);
  return 0;
}
