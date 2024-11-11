#include <bits/stdc++.h>
using namespace std;
int main() {
  int o = 0, e = 0, n, a, s = 0;
  cin >> n;
  while (n--) cin >> a, a % 2 == 0 ? e++ : o++, s += a;
  return (cout << (s % 2 == 0 ? e : o)) && 0;
}
