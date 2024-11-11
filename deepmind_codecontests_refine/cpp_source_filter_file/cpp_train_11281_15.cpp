#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int t, n;
struct node {
  int alg;
  int code;
  int idx;
} p[200010];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (register int i = 1; i <= 2 * n - 1; ++i) {
      scanf("%d%d", &p[i].alg, &p[i].code);
      p[i].idx = i;
    }
    sort(p + 1, p + 1 + 2 * n - 1,
         [=](node a, node b) { return a.alg > b.alg; });
    puts("YES");
    printf("%d ", p[1].idx);
    long long algSum = 0, codeSum = 0;
    for (int i = 2; i <= 2 * n - 1; ++i) {
      if (i & 1)
        algSum += p[i].code;
      else
        codeSum += p[i].code;
    }
    if (algSum > codeSum) {
      for (int i = 2; i <= 2 * n - 1; i += 2) printf("%d ", p[i].idx);
    } else {
      for (int i = 3; i <= 2 * n - 1; i += 2) printf("%d ", p[i].idx);
    }
    cout << endl;
  }
  return 0;
}
