#include <bits/stdc++.h>
using namespace std;
int n;
int p2[30];
int q[100005], p[100005];
bool fq, fp;
void init() {
  fq = fp = 1;
  p2[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = q[i] = i;
  for (int i = 1; i < 30; i++) p2[i] = p2[i - 1] * 2;
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = n; i > 0;) {
    int k = *upper_bound(p2, p2 + 30, i);
    int j = (k - 1) ^ i;
    if (j == 0) fp = 0;
    reverse(p + j, p + i + 1);
    i = j - 1;
  }
  if (fp) {
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d%c", p[i], i == n ? '\n' : ' ');
  } else {
    puts("NO");
  }
  if (*lower_bound(p2, p2 + 30, n) == n || n < 6) {
    puts("NO");
  } else if (n == 6) {
    puts("YES");
    puts("3 6 2 5 1 4");
  } else {
    puts("YES");
    int s[] = {0, 7, 3, 2, 5, 6, 4, 1};
    for (int i = 1; i <= 7; i++) q[i] = s[i];
    for (int i = 8; i < n;) {
      int k = *upper_bound(p2, p2 + 30, i);
      int j = min(k - 1, n);
      for (int g = i; g < j; g++) q[g] = q[g + 1];
      q[j] = i;
      i = j + 1;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", q[i], i == n ? '\n' : ' ');
  }
  return 0;
}
