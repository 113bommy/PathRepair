#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int n_ = 1e5 + 5;
int t, n;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", max(n - 2, 0));
  }
  return 0;
}
