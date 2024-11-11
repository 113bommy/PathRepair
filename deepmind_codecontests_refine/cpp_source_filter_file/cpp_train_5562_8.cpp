#include <bits/stdc++.h>
using namespace std;
long long M = (int)1e9 + 7;
long long f[50][50][2];
int K;
long long dfs(int cur, int nbase, int alreadyless) {
  if (cur < 0) return 1;
  long long &res = f[cur][nbase][alreadyless];
  if (res >= 0) return res;
  res = 0;
  int flag = K >> cur & 1;
  if (alreadyless || flag) {
    res += dfs(cur - 1, nbase + 1, alreadyless);
    res %= M;
  }
  if (nbase == 0) {
    res += dfs(cur - 1, nbase, alreadyless | flag);
    res %= M;
  } else {
    if (alreadyless || flag) {
      res += dfs(cur - 1, nbase, alreadyless | flag) * (1LL << (nbase - 1));
      res %= M;
    }
    res += dfs(cur - 1, nbase, alreadyless | flag) * (1LL << (nbase - 1));
    res %= M;
  }
  res %= M;
  return res;
}
int main() {
  cin >> K;
  memset(f, -1, sizeof(f));
  cout << dfs(31, 0, 0) << endl;
  return 0;
}
