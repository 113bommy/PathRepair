#include <bits/stdc++.h>
using namespace std;
int dcmp(double x, double y) {
  return fabs(x - y) <= 1e-8 ? 0 : x < y ? -1 : 1;
}
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MAX = 2000 + 5;
long long person[MAX / 2], keys[MAX];
long long n, k, p, ans;
int main(void) {
  ans = 1e16;
  scanf("%I64d%I64d", &n, &k);
  scanf("%I64d", &p);
  for (int(i) = (1); i <= (int)(n); (i)++) scanf("%I64d", &person[i]);
  for (int(i) = (1); i <= (int)(k); (i)++) scanf("%I64d", &keys[i]);
  sort(keys + 1, keys + 1 + k);
  sort(person + 1, person + 1 + n);
  for (int(i) = (1); i <= (int)(k - n + 1); (i)++) {
    long long mini = -1e16;
    for (int(j) = (1); j <= (int)(n); (j)++)
      mini = max(abs(person[j] - keys[j + i - 1]) + abs(p - keys[j + i - 1]),
                 mini);
    ans = min(mini, ans);
  }
  cout << ans;
}
