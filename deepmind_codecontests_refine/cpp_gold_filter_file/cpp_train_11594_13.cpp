#include <bits/stdc++.h>
using namespace std;
int s, k, i, j;
long long f[50];
vector<long long> v;
int main() {
  scanf("%d %d", &s, &k);
  f[0] = 1;
  for (i = 1; f[i - 1] <= s; i++)
    for (j = 1; j <= i && j <= k; j++) f[i] += f[i - j];
  for (i -= 2; i >= 0; i--)
    if (f[i] <= s) v.push_back(f[i]), s -= f[i];
  v.push_back(0);
  printf("%d\n", v.size());
  for (i = v.size() - 1; i > 0; i--) printf("%I64d ", v[i]);
  printf("%I64d\n", v[i]);
  return 0;
}
