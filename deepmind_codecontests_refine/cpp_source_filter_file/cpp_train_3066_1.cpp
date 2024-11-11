#include <bits/stdc++.h>
using namespace std;
int i, j, n, c, d;
string a[105], b[105];
int main() {
  for (cin >> n; i++ < n; d += !c)
    for (cin >> a[i] >> b[i], j = c = 0; j++ < i;)
      c += a[i] == a[j] & b[i] == b[j];
  cout << d;
  return 0;
}
