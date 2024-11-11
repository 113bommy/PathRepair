#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<long, long> p;
  vector<pair<long, long> > v;
  long n, m, i, j, a, b1 = 0, c1 = 0, a1 = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a % 3 == 0) a1++;
    if (a % 3 == 1) b1++;
    if (a % 3 == 2) c1++;
  }
  cout << a1 / 2 + min(b1, c1);
  return 0;
}
