#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101000;
int n, cnt[MAXN];
long long a[MAXN];
vector<long long> f[61];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    for (int i = 60; i >= 0; i--)
      if (x & (1LL << i)) {
        f[i].push_back(x);
        cnt[i]++;
        break;
      }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (int j = 0; j <= 60; j++)
      if ((!(sum & (1LL << j))) && cnt[j]) {
        a[i] = f[j][--cnt[j]];
        sum ^= a[i];
        flag = 1;
        break;
      }
    if (!flag) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
  return 0;
}
