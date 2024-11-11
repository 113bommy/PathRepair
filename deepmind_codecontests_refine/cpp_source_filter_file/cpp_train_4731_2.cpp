#include <bits/stdc++.h>
using namespace std;
int c[24];
int n, leafcnt, intern;
bool cache[12][1 << 12][24];
void dp(int index, int visited, int leafused) {
  if (index == intern) {
    if (leafused == leafcnt) {
      printf("YES");
      exit(0);
    }
    return;
  }
  if (cache[index][visited][leafused]) return;
  cache[index][visited][leafused] = true;
  if (~visited & (1 << index)) {
    return;
  }
  int child, tmp, sum, i, cnt;
  for (child = 0; child < (1 << intern); child++) {
    if (visited & child) continue;
    for (i = 0, tmp = child, sum = 0, cnt = 0; tmp; i++, tmp >>= 1) {
      if (tmp & 1) {
        sum += c[i];
        cnt++;
      }
    }
    if (c[index] >= sum + 1 && cnt + c[index] - sum - 1 >= 2 &&
        leafused + c[index] - sum - 1 <= leafcnt) {
      dp(index + 1, visited | child, leafused + c[index] - sum - 1);
    }
  }
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", c + i);
    if (c[i] == 1) leafcnt++;
  }
  if (n + 1 > 2 * leafcnt) {
    printf("NO");
    return 0;
  }
  intern = n - leafcnt;
  sort(c, c + n, greater<int>());
  dp(0, 1, 0);
  printf("NO");
  return 0;
}
