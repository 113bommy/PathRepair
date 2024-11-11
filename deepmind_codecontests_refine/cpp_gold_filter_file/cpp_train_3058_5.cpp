#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  for (int(j) = (0); (j) < (10); (j)++)
    if ((a * 10 + j) % b == 0) {
      cout << a << j;
      for (int(i) = (1); (i) < (n); (i)++) cout << 0;
      return 0;
    }
  cout << -1;
  return 0;
}
