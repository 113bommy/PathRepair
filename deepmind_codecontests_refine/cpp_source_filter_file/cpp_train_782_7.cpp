#include <bits/stdc++.h>
using namespace std;
int bo;
long long x;
long long getx3(long long n) { return n * n * n; }
void dfs(long long m, int dep, long long sum) {
  if (m == 0) {
    if (dep > bo || (dep == bo && sum > x)) {
      bo = dep;
      x = sum;
    }
  } else {
    long long i = 1;
    while (getx3(i + 1) <= m) ++i;
    dfs(m - getx3(i), dep + 1, sum + getx3(i));
    dfs(getx3(i) - 1 - getx3(i - 1), dep + 1, getx3(i - 1));
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  long long m;
  cin >> m;
  x = 0;
  bo = 0;
  dfs(m, 0, 0);
  cout << bo << " " << x << endl;
  return 0;
}
