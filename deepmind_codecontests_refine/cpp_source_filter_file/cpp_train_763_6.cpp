#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, i, s;
long long d[1000006];
int main() {
  scanf("%d %d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &x, &y);
    d[x]++;
    d[y]++;
  }
  for (i = 1; i <= m; i++) s += d[i] * (n - d[i] - 1);
  s /= 2;
  cout << (n * (n - 1) * (n - 2)) / 6 - s << endl;
}
