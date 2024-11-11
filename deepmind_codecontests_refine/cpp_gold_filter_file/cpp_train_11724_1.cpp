#include <bits/stdc++.h>
using namespace std;
struct Val {
  int val;
  int pos;
  Val();
  Val(int a, int b) {
    val = a;
    pos = b;
  }
};
bool operator<(const Val& a, const Val& b) { return a.val < b.val; }
int c[300010];
int ans[300010];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  long long res = 0;
  long long cursum = 0;
  priority_queue<Val> q;
  for (int i = 1; i <= n + k; i++) {
    if (i <= n) {
      cursum += c[i];
      q.push(Val(c[i], i));
    }
    if (i > k) {
      int p = q.top().pos;
      q.pop();
      cursum -= c[p];
      ans[p] = i;
    }
    res += cursum;
  }
  printf("%I64d\n", res);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
