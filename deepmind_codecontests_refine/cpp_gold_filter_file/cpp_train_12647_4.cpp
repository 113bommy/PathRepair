#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
const int maxn = 501010;
const int maxn4 = 4 * maxn;
const long long inf = 2020202020202020202LL;
int n, q, a[maxn], clr[maxn], pow2[25];
int pr[maxn];
long long num[maxn];
vector<vector<pair<int, int>>> pri(maxn);
void do_primes() {
  pr[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!pr[i])
      for (int j = i; j < maxn; j += i) pr[j] = i;
  }
}
int main() {
  cin >> n >> q;
  do_primes();
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  pow2[0] = 1;
  for (int i = 0; i < 20; i++) pow2[i + 1] = pow2[i] * 2;
  for (int i = 0; i < n; i++)
    if (!pri[a[i]].size()) {
      int x = a[i];
      vector<int> pri2;
      while (x != 1) {
        int y = pr[x];
        pri2.push_back(pr[x]);
        while ((x % y) == 0) x = x / y;
      }
      int u = pow2[pri2.size()];
      for (int j = 0; j < u; j++) {
        int z = 1;
        int r = 1;
        for (int k = 0; k < pri2.size(); k++)
          if (j & pow2[k]) {
            z *= pri2[k];
            r = -r;
          }
        pri[a[i]].push_back(make_pair(z, r));
      }
    }
  long long res = 0;
  for (int i = 0; i < q; i++) {
    int c;
    scanf("%d", &c);
    c--;
    clr[c] ^= 1;
    if (clr[c]) {
      long long ans = res;
      int p = a[c];
      for (int j = 0; j < pri[p].size(); j++) {
        ans = ans + num[pri[p][j].first] * pri[p][j].second;
        num[pri[p][j].first]++;
      }
      res = ans;
    } else {
      long long ans = res;
      int p = a[c];
      for (int j = 0; j < pri[p].size(); j++) {
        num[pri[p][j].first]--;
        ans = ans - num[pri[p][j].first] * pri[p][j].second;
      }
      res = ans;
    }
    printf("%I64d \n", res);
  }
  return 0;
}
