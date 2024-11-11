#include <bits/stdc++.h>
using namespace std;
set<long long> gao;
vector<long long> b;
int main() {
  int n, m, h, s[0x1000];
  int sum = 0;
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= m; ++i) scanf("%d", s + i), sum += s[i];
  if (sum < n) {
    puts("-1.0");
    return 0;
  }
  if (s[h] == 1) {
    puts("0.0");
    return 0;
  }
  if (sum - s[h] < n - 1 || sum == n) {
    puts("1.0");
    return 0;
  }
  double fenmu = 1, fenzi = 1;
  for (int i = 1; i < s[h]; ++i) fenzi *= (sum - i);
  for (int i = 1; i < s[h] - 1; ++i) fenmu *= (sum - n - i);
  printf("%.11f\n", 1 - fenmu / fenzi);
}
