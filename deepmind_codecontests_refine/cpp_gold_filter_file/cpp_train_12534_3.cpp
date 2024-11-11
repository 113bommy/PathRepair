#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 10;
bool isP[MAXN];
vector<int> p;
long long int rval[10];
long long int dval[10];
int n;
map<long long int, int> dp;
int fact(long long int x) {
  if (x < 2) return 0;
  if (x < MAXN && !isP[x]) return 1;
  int& ans = dp[x];
  if (ans) return ans;
  for (int i = 0; i < p.size(); i++) {
    if (x % p[i] == 0) return ans = 1 + fact(x / p[i]);
  }
  return ans = 1;
}
int root;
int best = -1;
void ccal() {
  int t = 0;
  for (int i = 0; i < n; i++) {
    int xx = fact(dval[i]);
    t += xx;
    if (dval[i] != rval[i] || xx > 1) t++;
  }
  if (root > 1) t++;
  if (best == -1 || best > t) best = t;
}
void dfs(int x) {
  if (!x) {
    ccal();
    return;
  }
  for (int i = 0; i < x; i++) {
    if (dval[i] % rval[x] == 0) {
      dval[i] /= rval[x];
      root--;
      dfs(x - 1);
      dval[i] *= rval[x];
      root++;
    }
  }
  dfs(x - 1);
}
int main() {
  for (int i = 2; i < MAXN; i++) {
    if (isP[i]) continue;
    p.push_back(i);
    for (int j = i + i; j < MAXN; j += i) isP[j] = true;
  }
  cin >> n;
  root = n;
  for (int i = 0; i < n; i++) cin >> rval[i];
  sort(rval, rval + n, greater<long long int>());
  for (int i = 0; i < n; i++) dval[i] = rval[i];
  dfs(n - 1);
  cout << best << endl;
  return 0;
}
