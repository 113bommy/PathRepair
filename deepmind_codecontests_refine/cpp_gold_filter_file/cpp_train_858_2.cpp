#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long p) { return power(a, p - 2, p); }
long long gcd(long long x, long long y) {
  if (x == 0 || y == 0) {
    return max(y, x);
  }
  return gcd(y % x, x);
}
long long arr[100005];
long long n;
vector<long long> edge[100006];
long long dp[100005];
void dfs(long long cur, long long par) {
  long long sum = 1;
  long long sizes = 0;
  for (auto p : edge[cur]) {
    if (p != par) {
      dfs(p, cur);
      sizes = max(arr[p], sizes);
      sum += arr[p];
    }
  }
  sizes = max(sizes, n - sum);
  arr[cur] = sum;
  dp[cur] = sizes;
}
int main() {
  long long T;
  scanf("%lld", &T);
  ;
  while (T--) {
    scanf("%lld", &n);
    for (long long i = 1; i < n; i++) {
      long long x, y;
      scanf("%lld %lld", &(x), &(y));
      edge[x].push_back(y);
      edge[y].push_back(x);
    }
    long long mini = 1e10;
    vector<long long> a;
    dfs(1, 0);
    for (long long i = 1; i <= n; i++) mini = min(dp[i], mini);
    for (long long i = 1; i <= n; i++)
      if (dp[i] == mini) a.push_back(i);
    if (a.size() == 1) {
      cout << edge[a[0]][0] << " " << a[0] << endl;
      cout << edge[a[0]][0] << " " << a[0] << endl;
    } else {
      assert(a.size() == 2);
      long long c1 = a[0];
      long long c2 = a[1];
      long long z = 0;
      for (auto p : edge[c1]) {
        if (p != c2) {
          z = p;
          break;
        }
      }
      cout << c1 << " " << z << endl;
      cout << c2 << " " << z << endl;
    }
    for (long long i = 0; i <= n; i++) {
      edge[i].clear();
      dp[i] = 0;
      arr[i] = 0;
    }
  }
}
