#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
long long Hep[N];
int len = 0;
void Push(int x) {
  Hep[++len] = ~x;
  push_heap(Hep + 1, Hep + 1 + len);
}
long long Pop() {
  pop_heap(Hep + 1, Hep + 1 + len);
  return ~Hep[len--];
}
int main(void) {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    long long sum = 0;
    for (int i = 1, tmp; i <= n; i++) {
      scanf("%d", &tmp);
      long long ans = 0;
      Push(sum + a[i]);
      sum += tmp;
      while (len && ~Hep[1] <= sum) ans += Pop() - sum + tmp;
      printf("%I64d ", ans + (long long)tmp * len);
    }
    puts("");
  }
  return 0;
}
