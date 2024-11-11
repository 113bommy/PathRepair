#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > mul(vector<vector<long long> > a,
                               vector<vector<long long> > b) {
  vector<vector<long long> > c(a.size(), vector<long long>(b[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int x = 0; x < b[0].size(); x++) {
      for (int j = 0; j < b.size(); j++)
        c[i][x] = (c[i][x] + a[i][j] * b[j][x]) % 1000000007;
    }
  }
  return c;
}
vector<vector<long long> > pow(vector<vector<long long> > a, long long x) {
  if (x == 1) return a;
  vector<vector<long long> > tmp = pow(a, x / 2);
  tmp = mul(tmp, tmp);
  if (x % 2) tmp = mul(tmp, a);
  return tmp;
}
long long arr[105];
int main() {
  long long k;
  int n;
  scanf("%d%I64d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%I64d", &arr[i]);
  if (k == 1) {
    printf("%d", n);
    return 0;
  }
  vector<vector<long long> > a(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < n; x++) {
      if (__builtin_popcount(arr[i] ^ arr[x]) % 3 == 0) a[i][x] = 1;
    }
  }
  a = pow(a, k - 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < n; x++) ans = (ans + a[i][x]) % 1000000007;
  }
  printf("%I64d", ans);
}
