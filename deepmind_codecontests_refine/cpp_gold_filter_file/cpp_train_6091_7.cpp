#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, k;
ll arr[N], ft[N], val[N], old[N];
void add(int i, ll x) {
  for (; i <= n; i += i & -i) ft[i] += x;
}
ll query(int i) {
  ll ans = 0;
  for (; i > 0; i -= i & -i) ans += ft[i];
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &arr[i]);
    val[i] = 1;
  }
  ll sum = n;
  while (k--) {
    for (int i = 1; i <= n; ++i) {
      ft[i] = 0;
      old[i] = val[i];
    }
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      val[i] = query(arr[i]);
      sum += val[i];
      add(arr[i] + 1, old[i]);
    }
  }
  printf("%I64d", sum);
  return 0;
}
