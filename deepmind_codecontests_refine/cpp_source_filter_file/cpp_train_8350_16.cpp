#include <bits/stdc++.h>
using namespace std;
long long BSDK() {
  int h, m;
  scanf("%d %d", &h, &m);
  return h * 60 + m;
}
int main() {
  int i, t;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    printf("%lld\n", BSDK());
  }
  return 0;
}
