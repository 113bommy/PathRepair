#include <bits/stdc++.h>
using namespace std;
int n, m, dp[5000000][4];
const int prime[4][7] = {{7, 17, 37, 47, 61, 97, -1},
                         {11, 13, 41, 43, 67, 89, -1},
                         {2, 3, 23, 31, 53, 71, 83},
                         {5, 19, 29, 59, 73, 79, -1}};
const int MOD[4] = {1224469897, 1503325967, 1336143462, 937397015};
long long a[10005];
struct Recipe {
  char s[33];
  long long c;
  int d, ans, num;
} data[10005 * 3];
bool cmp1(Recipe a, Recipe b) { return a.d < b.d; }
bool cmp2(Recipe a, Recipe b) { return a.num < b.num; }
int pow(int base, int k) {
  int ret = 1;
  for (int o = 0; o < k; o++) ret *= base;
  return ret;
}
void solve(int base, int len) {
  int l[len];
  int state = pow(base + 1, len);
  for (int i = 0; i < state; i++) {
    for (int k = 0, x = i; k < len; k++, x /= (base + 1)) l[k] = x % (base + 1);
    int num = 0, j = -1;
    for (int k = 0, t = 1; k < len; k++, t *= base) {
      if (l[k] == base) {
        j = k;
        break;
      }
      num += l[k] * t;
    }
    if (j == -1) {
      for (int z = 0; z < 4; z++) dp[i][z] = (num >= n) ? 1 : (a[num] % MOD[z]);
      continue;
    }
    for (int z = 0; z < 4; z++) {
      dp[i][z] = 1;
      int d = pow(base + 1, j);
      for (int o = 0, t = d; o < base; o++, t += d)
        dp[i][z] = ((long long)dp[i][z] * dp[i - t][z]) % MOD[z];
    }
  }
}
int compute(int base, char *s, int len) {
  int i = 0, j, ret = 0, t = 1;
  for (j = 0; j < len && s[j]; j++) {
    int k;
    if (s[j] == '?')
      k = base;
    else if (s[j] >= '0' && s[j] <= '9')
      k = s[j] - '0';
    else
      k = s[j] - 'A' + 10;
    ret += k * t;
    t *= (base + 1);
  }
  for (; s[j]; j++)
    if (s[j] != '?' && s[j] != '0') return -1;
  return ret;
}
void check(int &x, int y) {
  if (x == -1 || x > y) x = y;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%s", &data[i].d, data[i].s);
    cin >> data[i].c;
    reverse(data[i].s, data[i].s + strlen(data[i].s));
    data[i].num = i;
    data[i].ans = -1;
  }
  sort(data, data + m, cmp1);
  int now = -1, ln;
  for (int i = 0; i < m; i++) {
    now = data[i].d;
    ln = 1;
    for (int x = now; x <= n; x *= now, ln++)
      ;
    solve(now, ln);
    for (int j = i; data[j].d == now; j++) {
      if (data[j].ans != -1) continue;
      int k = compute(now, data[j].s, ln);
      if (k == -1) continue;
      for (int z = 0; z < 4; z++)
        for (int t = 0; t < 7; t++) {
          if (prime[z][t] == -1) continue;
          if ((dp[k][z] % prime[z][t] + data[j].c % prime[z][t]) %
                  prime[z][t] ==
              0)
            check(data[j].ans, prime[z][t]);
        }
    }
    while (data[i].d == now) i++;
    i--;
  }
  sort(data, data + m, cmp2);
  for (int i = 0; i < m; i++) {
    if (data[i].ans == -2) data[i].ans++;
    printf("%d\n", data[i].ans);
  }
  return 0;
}
