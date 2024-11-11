#include <bits/stdc++.h>
using namespace std;
int main() {
  long long v[4], k;
  scanf("%lld", &k);
  for (int i = (k + 1); i <= (9000); i++) {
    v[3] = i % 10;
    v[2] = (int)(i % 100 / 10);
    v[1] = (int)(i % 1000 / 100);
    v[0] = (int)(i / 1000);
    if (v[0] != v[1] && v[2] != v[1] && v[2] != v[3] && v[0] != v[2] &&
        v[0] != v[3] && v[1] != v[3]) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
