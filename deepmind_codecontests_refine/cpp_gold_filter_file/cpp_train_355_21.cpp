#include <bits/stdc++.h>
using namespace std;
using namespace std;
int q[500005];
bool cmp(int x, int y) { return x < y; }
int main() {
  int n;
  scanf("%d", &n);
  int top = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    while (top > 1 && q[top - 2] >= q[top - 1] && q[top - 1] < x) {
      ans += min(x, q[top - 2]);
      top--;
    }
    q[top++] = x;
  }
  for (int i = 1; i < top - 1; i++) ans += min(q[i - 1], q[i + 1]);
  printf("%lld\n", ans);
  return 0;
}
