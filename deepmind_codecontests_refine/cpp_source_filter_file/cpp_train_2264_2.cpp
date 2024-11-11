#include <bits/stdc++.h>
using namespace std;
int n, i, j, sum = 0, a[110], jyz;
int main() {
  cin >> n;
  n *= 2;
  for (register int i = (1); i <= (n); i++) cin >> a[i];
  while (n) {
    jyz = 1;
    while (a[jyz] != a[n]) jyz++;
    sum += n - jyz - 1;
    for (register int j = (jyz); j <= (n - 1); j++) swap(a[j], a[j + 1]);
    n -= 2;
  }
  cout << sum << "\n";
  return 0;
}
