#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200100];
long long que[5];
int ans = 0;
bool judge(int pos2, int pos1) {
  if ((a[pos2] - a[pos1]) % (pos2 - pos1) == 0) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  int s = 1;
  int top = 0;
  int cnt = 0;
  long long q = 0;
  for (int i = 1; i <= n; i++) {
    cnt++;
    if (a[i] != -1 && top < 2) que[++top] = i;
    if (top == 2) {
      if (!judge(que[2], que[1]) ||
          (a[i] != -1 && a[i] != a[que[2]] - q * (que[2] - i))) {
        ans++;
        s = i, top = 0, cnt = 0;
        i--;
        continue;
      }
      q = (a[que[2]] - a[que[1]]) / (que[2] - que[1]);
      long long fval = a[que[2]] - q * (que[2] - s);
      long long lval = a[que[2]] - q * (que[2] - i);
      if (fval <= 0 || lval <= 0) {
        ans++;
        s = i, top = 0, cnt = 0;
        i--;
        continue;
      }
    }
  }
  if (cnt) ans++;
  printf("%d\n", ans);
  return 0;
}
