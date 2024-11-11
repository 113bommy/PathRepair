#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
const long long MOD = 1000000007LL;
int n;
char str[N], que[N];
long long ans = 0, val[20], len[20];
vector<string> s;
long long fpow(long long a, long long k) {
  if (k == 0) return 1LL;
  if (k % 2 == 0) {
    long long r = fpow(a, k / 2);
    return r * r % MOD;
  } else {
    return a * fpow(a, k - 1) % MOD;
  }
}
int main() {
  scanf("%s", str);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", que);
    s.push_back(string(que));
  }
  for (int i = 0; i < 10; i++) {
    val[i] = i;
    len[i] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    int u = s[i][0] - '0';
    long long new_val = 0;
    long long new_len = 0;
    for (int j = 3; j < (int)s[i].size(); j++) {
      int v = s[i][j] - '0';
      new_val = ((new_val * fpow(10LL, len[v]) % MOD) + val[v]) % MOD;
      new_len += len[v];
      if (new_len >= MOD - 1) new_len -= MOD - 1;
    }
    val[u] = new_val;
    len[u] = new_len;
  }
  int m = strlen(str);
  for (int i = 0; i < m; i++) {
    int u = str[i] - '0';
    ans = ((ans * fpow(10LL, len[u])) % MOD + val[u]) % MOD;
  }
  printf("%d\n", (int)ans);
  return 0;
}
