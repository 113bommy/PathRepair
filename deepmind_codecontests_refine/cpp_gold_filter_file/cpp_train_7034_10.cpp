#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int MOD = 1000000007;
int n, m;
int a[N], b[N];
char mm[10010];
vector<int> f[N];
long long w[2010];
int RM(int a) {
  if (!m) return 0;
  int t;
  for (int i = m - 1; i >= 0; i--) {
    t = w[i] % a;
    w[i] /= a;
    if (i) w[i - 1] += t * 1000000000ll;
  }
  while (m && !w[m - 1]) m--;
  return t;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
  a[1] = 1;
  a[n + 1] = 1000000000;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  scanf("%s", mm);
  for (int i = strlen(mm) - 1; i >= 0; i -= 9, m++)
    for (int j = max(0, i - 8); j <= i; w[m] = w[m] * 10 + mm[j++] - '0')
      ;
  f[1].push_back(1);
  for (int i = 1; i <= n; i++) {
    int s = f[i].size(), sum = 0, md = 0;
    if (a[i + 1] != 1) md = RM(a[i + 1]);
    for (int j = 0; j < s + b[i]; j++) {
      if (j < s) (sum += f[i][j]) %= MOD;
      if (j > b[i]) (sum += MOD - f[i][j - b[i] - 1]) %= MOD;
      if (j % a[i + 1] == md) f[i + 1].push_back(sum);
    }
  }
  printf("%d\n", m ? 0 : f[n + 1].size() == 0 ? 0 : f[n + 1][0]);
  return 0;
}
