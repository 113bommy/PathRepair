#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n, w = 0, tmp;
  scanf("%lld%lld", &n, &h);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &tmp);
    if (tmp > h)
      w += 2;
    else
      w++;
  }
  cout << w << endl;
  return 0;
}
