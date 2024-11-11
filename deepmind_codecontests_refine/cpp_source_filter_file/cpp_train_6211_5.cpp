#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long LL_MAX = 9223372036854775807;
using namespace std;
map<double, int> m;
double da[2 * 100005];
int n;
int main() {
  scanf("%d", &n);
  int a, b, c;
  for (int i = 0; i < n; i++) {
    scanf("(%d+%d)/%d", &a, &b, &c);
    da[i] = (a + b) / (c * 1.0);
    m[da[i]]++;
  }
  for (int i = 0; i < n; i++) printf("%d ", m[da[i]]);
  printf("\n");
  return 0;
}
