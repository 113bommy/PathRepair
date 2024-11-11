#include <bits/stdc++.h>
using namespace std;
struct __timestamper {};
const int MAXN = 1000100;
char s[MAXN];
int z[MAXN];
char ans[MAXN];
int anssum[MAXN];
int main() {
  int n, k;
  scanf("%d%d%s", &n, &k, s);
  {
    int l, r;
    l = r = 0;
    for (int i = 1; i < n; i++) {
      if (i <= r) {
        z[i] = min(r - i + 1, z[i - l]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    int lf = i * k;
    int rg = min(i * (k + 1), i + z[i]);
    if (lf > n) break;
    if (lf > rg) continue;
    anssum[lf]++;
    anssum[rg + 1]--;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += anssum[i + 1];
    ans[i] = sum > 0 ? '1' : '0';
  }
  puts(ans);
  return 0;
}
