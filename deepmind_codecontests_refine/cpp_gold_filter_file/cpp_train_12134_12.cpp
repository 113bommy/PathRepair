#include <bits/stdc++.h>
using namespace std;
long long a[100007];
long long b, c, d, e, f, j, h, l, m, n, ma, p, i, x;
char k;
string s;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  c = 1;
  ma = 1;
  for (i = 2; i <= n; i++) {
    if (a[i] > a[i - 1])
      c++;
    else
      c = 1;
    if (c > ma) ma = c;
  }
  cout << ma << endl;
  return 0;
}
