#include <bits/stdc++.h>
using namespace std;
long long int n;
int m, temp;
vector<int> w;
int main() {
  scanf("%I64d %d", &n, &m);
  for (int a = 0; a < m; a++) {
    scanf("%d", &temp);
    scanf("%d", &temp);
    w.push_back(temp);
  }
  sort(w.begin(), w.end());
  int k1 = (int)floor((1 + sqrt(1 + 4 * (2 * n - 2))) / 2.0);
  if (k1 % 2 == 0) k1--;
  int k2 = (int)floor(sqrt(n * 2.0));
  if (k2 % 2 == 1) k2--;
  int k = max(k1, k2);
  int i = m - 1;
  long long int ans = 0;
  while (k != 0) {
    if (i >= 0) ans += w.at(i);
    i--;
    k--;
  }
  printf("%I64d\n", ans);
  return 0;
}
