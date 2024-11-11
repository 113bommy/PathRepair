#include <bits/stdc++.h>
using namespace std;
const int MAX = 112345;
long long data[MAX], pre[MAX];
long long ans[MAX];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &data[i]);
  }
  sort(data + 1, data + 1 + n, greater<long long>());
  for (int i = 1; i <= n; i++) pre[i] = data[i] + pre[i - 1];
  for (long long i = 1; i < MAX; i++) {
    long long cnt = 1;
    long long st = 2;
    long long step = i;
    for (; st + step - 1 <= n; st += step, cnt++, step *= i) {
      ans[i] += (pre[st + i - 1] - pre[st - 1]) * cnt;
    }
    if (st <= n) {
      ans[i] += (pre[n] - pre[st - 1]) * cnt;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    printf("%lld ", ans[t]);
  }
}
