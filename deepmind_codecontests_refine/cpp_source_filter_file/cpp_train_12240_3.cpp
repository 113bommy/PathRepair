#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> m >> n >> k;
  long long int n1 = n * 2, c = 1;
  long long int n2 = n1;
  while (n1 <= k) {
    n1 += n2;
    c++;
    if (n1 == k) break;
  }
  long long int c1 = 0;
  if (k & 1) {
    for (long long int i = n1 - n2 + 1; i <= n1; i += 2) {
      c1++;
      if (i == k) break;
    }
    cout << c << " " << c1 << " "
         << "L" << '\n';
  } else {
    for (long long int i = n1 - n2 + 2; i <= n1; i += 2) {
      c1++;
      if (i == k) break;
    }
    cout << c << " " << c1 << " "
         << "R" << '\n';
  }
  return 0;
}
