#include <bits/stdc++.h>
using namespace std;
const int P = 3e6;
int cnt[P + 1];
long long ans[P + 1];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    int t;
    scanf("%d", &t);
    cnt[t]++;
  }
  for (int i = 1; i <= P; i++)
    for (int j = 1; j * 1ll * i <= P; j++)
      ans[i * j] +=
          (i == j ? cnt[i] * 1ll * (cnt[i] - 1) : cnt[i] * 1ll * cnt[j]);
  long long all = n * 1ll * (n - 1);
  long long sum = 0;
  for (int i = 1; i <= P; i++) sum += ans[i];
  ans[P] += all - sum;
  for (int i = P; i >= 1; i--) ans[i] += (i == P) ? 0 : ans[i + 1];
  int m;
  cin >> m;
  for (int i = 0; i < (m); i++) {
    int t;
    scanf("%d", &t);
    printf("%I64d\n", ans[t]);
  }
  return 0;
}
