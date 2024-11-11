#include <bits/stdc++.h>
using namespace std;
long long f[55];
vector<int> work(int n, int k) {
  vector<int> ans;
  if (!n) return ans;
  if (k <= f[n - 1]) {
    ans.push_back(1);
    vector<int> res = work(n - 1, k);
    for (int x = 0; x < res.size(); ++x) {
      ans.push_back(res[x] + 1);
    }
    return ans;
  } else {
    ans.push_back(2);
    ans.push_back(1);
    vector<int> res = work(n - 2, k - f[n - 1]);
    for (int x = 0; x < res.size(); ++x) ans.push_back(res[x] + 2);
    return ans;
  }
}
int main() {
  int n;
  long long k;
  scanf("%d %lld", &n, &k);
  f[0] = f[1] = 1LL;
  for (int x = 2; x <= n; ++x) f[x] = f[x - 1] + f[x - 2];
  vector<int> ans = work(n, k);
  for (int x = 0; x < ans.size(); ++x) printf("%d ", ans[x]);
}
