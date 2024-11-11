#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g[2000006], h, i, j, k;
long long tmp;
long long an;
long long an1;
bool cmp(long long x, long long y) { return x > y; }
int main() {
  cin >> a >> b;
  for (i = 1; i <= b; i++) cin >> c >> g[i];
  sort(g + 1, g + b + 1, cmp);
  for (i = 1; i <= b; i++) {
    tmp = (i * (i - 1)) / 2;
    if (i % 2 == 0) tmp += i / 2;
    if (tmp < a) an = i;
  }
  for (i = 1; i <= an; i++) an1 += g[i];
  cout << an1 << endl;
  return 0;
}
