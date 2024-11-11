#include <bits/stdc++.h>
using namespace std;
long long p, q;
vector<int> fact(int x) {
  vector<int> ans;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) {
    ans.push_back(x);
  }
  return ans;
}
long long calc(vector<int>& a) {
  int a0 = a[0];
  long long ans = 1e18;
  for (a0 = a[0] - 1; a0 <= a[0] + 1; a0++) {
    vector<int> cands = fact(a0);
    for (int i = 0; i < (int)cands.size(); i++) {
      vector<int> costs(a.size());
      long long curans = 0;
      for (int j = 0; j < (int)a.size(); j++) {
        if (a[j] % cands[i] == 0) {
          costs[j] = 0;
        } else if ((a[j] - 1) % cands[i] == 0 || (a[j] + 1) % cands[i] == 0) {
          costs[j] = q;
        } else {
          costs[j] = 1e12;
        }
      }
      long long sum = 0;
      for (int j = 0; j < (int)a.size(); j++) {
        curans += costs[j];
      }
      sum = curans;
      for (int j = 0; j < (int)a.size(); j++) {
        costs[j] = costs[j] - p;
      }
      long long minPs = costs[0], curSum = costs[0];
      for (int i = 1; i < (int)a.size(); i++) {
        curSum += costs[i];
        curans = min(curans, sum - (curSum - minPs));
        minPs = min(minPs, curSum);
      }
      ans = min(ans, curans);
    }
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%d%d", &p, &q);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long ans = calc(a);
  reverse(a.begin(), a.end());
  ans = min(ans, calc(a));
  printf("%lld\n", ans);
}
