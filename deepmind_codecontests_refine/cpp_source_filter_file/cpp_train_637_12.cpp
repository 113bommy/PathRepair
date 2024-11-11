#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, odd1 = 0, odd = 0, evn1 = 0, evn = 0;
  cin >> n >> m;
  int a, b;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a % 2 == 0)
      evn++;
    else
      odd++;
  }
  for (i = 0; i < m; i++) {
    cin >> b;
    if (b % 2 == 0)
      evn1++;
    else
      odd++;
  }
  cout << min(evn, odd) + min(evn1, odd1);
}
