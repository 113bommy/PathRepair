#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
const int N = 205;
const long long oo = 1e18 + 1;
vector<int> ans;
int dp1[N][N];
long long dp2[N][N];
int pfix[N];
void pfunc() {
  pfix[1] = 0;
  for (int i = 1; i < (int)ans.size(); i++) {
    pfix[i + 1] = pfix[i];
    while (pfix[i + 1] && ans[pfix[i + 1]] != ans[i])
      pfix[i + 1] = pfix[pfix[i + 1]];
    pfix[i + 1] += ans[i] == ans[pfix[i + 1]];
  }
}
int mov(int s, int c) {
  if (s == 0) return ans[s] == c;
  if (s != ans.size() && ans[s] == c) return s + 1;
  return mov(pfix[s], c);
}
int f(int fi, int s) {
  if (fi == 0) return mov(s, 0);
  if (fi == 1) return mov(s, 1);
  int &ret = dp1[fi][s];
  if (ret != -1) return ret;
  return ret = f(fi - 1, f(fi - 2, s));
}
long long g(int fi, int s) {
  if (fi == 0) return mov(s, 0) == (int)ans.size();
  if (fi == 1) return mov(s, 1) == (int)ans.size();
  long long &ret = dp2[fi][s];
  if (ret != -1) return ret;
  return ret = min(oo, g(fi - 2, s) + g(fi - 1, f(fi - 2, s)));
}
int main() {
  int n, m;
  long long k;
  scanf("%d %lld %d", &n, &k, &m);
  for (int i = 0; i < m && k; i++) {
    memset(dp1, -1, sizeof dp1);
    ;
    memset(dp2, -1, sizeof dp2);
    ;
    ans.push_back(0);
    pfunc();
    long long x = g(n, 0);
    if (x < k) {
      k -= x;
      ans.pop_back();
      ans.push_back(1);
      memset(dp1, -1, sizeof dp1);
      memset(dp2, -1, sizeof dp2);
      pfunc();
      if (f(n, 0) == (int)ans.size()) k--;
    }
  }
  for (int j : ans) printf("%d", j);
  printf("\n");
  return 0;
}
