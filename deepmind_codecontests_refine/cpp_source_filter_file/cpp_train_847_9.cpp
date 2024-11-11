#include <bits/stdc++.h>
using namespace std;
long long a, b, m, i;
bool run() {
  long long mn = min(a, a % m - 1);
  for (i = 0; i <= mn; ++i) {
    long long r = (i * 1000000000) % m;
    if ((m - r) % m > b) return true;
  }
  return false;
}
int main() {
  cin >> a >> b >> m;
  if (run())
    printf("1 %09d\n", (int)i);
  else
    printf("2\n");
  return 0;
}
