#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int inf = 1 << 28;
double pi = acos(-1.0);
int main() {
  int flag = 1;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= 5 || (n - x) <= 4) flag = 0;
    if (y <= 5 || (m - y) <= 4) flag = 0;
  }
  if (!flag)
    puts("YES");
  else
    puts("NO");
  return 0;
}
