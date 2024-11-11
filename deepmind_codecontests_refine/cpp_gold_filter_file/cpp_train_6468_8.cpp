#include <bits/stdc++.h>
using namespace std;
int n;
char str[111];
vector<long long> seq;
long long d[111][111][111];
long long go(int start, int end, int prefix) {
  if (end - start <= 0) return 0;
  if (end - start == 1) return seq[prefix];
  long long& res = d[start][end][prefix];
  if (res != 0) return res;
  res = seq[prefix] + go(start + 1, end, 1);
  for (int i = start + 1; i < end; i++)
    if (str[i] == str[start])
      res = max(res, go(start + 1, i, 1) + go(i, end, prefix + 1));
  return res;
}
void solve() {
  memset(d, 0, sizeof(d));
  scanf("%d %s", &n, &str);
  seq.resize(n + 1);
  for (int i = 1; i <= n; ++i) scanf("%lld", &seq[i]);
  printf("%lld", go(0, n, 1));
}
int main() { solve(); }
