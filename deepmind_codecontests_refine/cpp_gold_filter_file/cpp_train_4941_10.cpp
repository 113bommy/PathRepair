#include <bits/stdc++.h>
using namespace std;
const int MM = 1200000;
long long int m, n, k, p1, p2, p3, p, f, a[MM];
string s, s1, s2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  m = sqrt(n);
  for (long long int i = 1; i <= m; i++) {
    if ((i + n) % 3 == 0) {
      if ((i * (i + 1)) / 2 <= (i + n) / 3) p1++;
    }
  }
  cout << p1;
  return 0;
}
