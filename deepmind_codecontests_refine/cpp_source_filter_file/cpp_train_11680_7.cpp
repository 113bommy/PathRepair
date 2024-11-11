#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, a[N], b[N * 2], c[N * 2], dp[N], sum;
int ans;
map<int, int> M[N];
int chu(int x) { return (x - 1) % n; }
void Solve(int l, int r) {
  c[l - 1] = 0;
  for (int i = l; i <= r; i++) c[i] = c[i - 1] + b[i] - sum;
  int i = l, j = l + (k - 1);
  while (j - (k - 2) <= r) {
    if (c[j] >= 0) {
      for (int o = j - (k - 1); o >= i; o -= k - 1) {
        printf("%d ", chu(o));
        int su = -c[o];
        printf("%d ", b[o] += su);
        for (int p = o + 1; p <= o + (k - 2); p++) {
          if (p <= n) {
            su += sum - b[p];
            printf("%d ", sum);
            b[p] = sum;
          } else
            printf("%d ", b[p - n]);
        }
        if (o + k - 1 > n)
          printf("%d\n", b[o + k - 1 - n]);
        else
          printf("%d\n", b[o + (k - 1)] -= su);
      }
      i = j;
    }
    j += k - 1;
  }
}
void solve(int l, int r) {
  c[l - 1] = 0;
  for (int i = l; i <= r; i++) c[i] = c[i - 1] + b[i] - sum;
  int i = l, j = l + (k - 1);
  while (j <= r) {
    if (c[j] >= 0) {
      for (int o = j - (k - 1); o >= i; o -= k - 1) {
        printf("%d ", chu(o));
        int su = -c[o];
        printf("%d ", b[o] += su);
        for (int p = o + 1; p <= o + (k - 2); p++) {
          su += sum - b[p];
          printf("%d ", su);
        }
        printf("%d\n", b[o + (k - 1)] -= su);
      }
      i = j;
    }
    j += k - 1;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i + n] = b[i] = a[i];
    sum += a[i];
  }
  sum /= n;
  for (int i = 1; i <= n; i++) a[i] = a[i] - sum + a[i - 1];
  for (int i = 1; i <= n; i++) {
    auto it = M[(i - 1) % (k - 1)].find(a[i]);
    if (it != M[(i - 1) % (k - 1)].end())
      dp[i] = it->second + 1;
    else
      dp[i] = 1;
    M[i % (k - 1)][a[i]] = max(M[i % (k - 1)][a[i]], dp[i]);
    ans = max(ans, dp[i]);
  }
  int jb = (n - ans + k - 2) / (k - 1);
  printf("%d\n", jb);
  if ((n - 1 + k - 2) / (k - 1) == jb) {
    Solve(1, n);
    return 0;
  }
  int an = n - 1 - jb * (k - 1);
  for (int i = 1; i <= n; i++)
    if (dp[i] == ans) {
      int j = i;
      for (int o = 1; o <= an; o++) {
        int O = j - 1;
        while ((j - O - 1) % (k - 1) || a[j] != a[O] || dp[O] + 1 != dp[j]) O--;
        solve(O + 1, j);
        j = O;
      }
      solve(i + 1, n + j);
      return 0;
    }
}
